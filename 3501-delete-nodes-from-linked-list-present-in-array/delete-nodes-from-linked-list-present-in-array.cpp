/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }

        ListNode *temp = head;
        while(head -> next != NULL) {
            if(mp.find(head -> next -> val) != mp.end()) {
                ListNode *node = head -> next;
                head -> next = node -> next;
                delete(node);
                continue;
            } else {
                head = head -> next;
            }
        }
        head = temp;
        if(mp.find(head -> val) != mp.end()) {
            ListNode *node = head;
            head = head -> next;
            delete(node);
        }
        return head;
    }
};
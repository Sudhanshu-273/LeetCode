class Solution {
public:
    string compressedString(string word) {
        char ch = word[0];
        int f = 1;
        string str = "";

        for(int i = 1; i < word.length(); ++i) {
            if(word[i] != ch || f >= 9) {
                str += to_string(f);
                str.push_back(ch);
                ch = word[i];
                f = 1;
            } else {
                ++f;
            }
        }
        str += to_string(f);
        str.push_back(ch);

        return str;
    }
};
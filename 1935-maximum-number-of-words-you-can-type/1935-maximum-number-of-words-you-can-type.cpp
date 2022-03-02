class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for(auto c: brokenLetters) broken[c-'a'] = true;
        
        int res = 0;
        stringstream ss(text);
        string word;
        while(ss >> word) {
            bool flag = true;
            for(auto c: word) {
                if(broken[c-'a']) {
                    flag = false;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
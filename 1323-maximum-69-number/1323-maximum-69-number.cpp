class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0;
        stringstream ss;
        ss << num;
        string s;
        ss >> s;
        int k = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '6' && k) {
                ans = ans * 10 + 9;
                k--;
            }
            else ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
};
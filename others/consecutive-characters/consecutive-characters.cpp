class Solution {
public:
    int maxPower(string s) {
        int ans = 1, cur = 1;
        for(int i = 1; i<s.size(); i++) {
            if(s[i] == s[i-1]) cur ++;
            else cur = 1;
            ans = ans < cur ? cur : ans;
        }
        return ans;
    }
};
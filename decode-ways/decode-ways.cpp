class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        int one_before = 1, two_before = 1;
        for(int i = 1; i < n; i++) {
            int cur = 0;
            if(s[i] != '0') cur = one_before;
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                cur += two_before;
            }
            two_before = one_before;
            one_before = cur;
        }
        return one_before;
    }
};
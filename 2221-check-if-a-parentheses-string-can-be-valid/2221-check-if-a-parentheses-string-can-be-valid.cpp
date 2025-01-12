class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) return false;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (s[i] == '(') ? 1 : -1;
            if (cnt < 0) {
                int j = i;
                while(j>=0 && cnt < 0) {
                    if(s[j] == ')') {
                        if (locked[j] == '0') {
                            cnt += 2;
                            s[j] = '(';
                        }
                    }
                    j--;
                }
            }
        }
        int j = n-1;
        while(j>=0 && cnt > 0) {
            if(s[j] == '(') {
                if (locked[j] == '0') {
                    cnt -= 2;
                    s[j] = ')';
                }
            }
            j--;
        }
        cnt = 0; 
        for(auto c: s) {
            cnt += (c == '(') ? 1 : -1;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
};
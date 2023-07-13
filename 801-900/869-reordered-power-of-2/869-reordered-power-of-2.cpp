class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s = "";
        while (N > 0) {
            s += (N % 10 + '0');
            N /= 10;
        }
        sort(s.begin(), s.end());
        do {
            int t = 0;
            if (s[0] == '0') continue;
            for (auto x : s) {
                t = t * 10 + (x - '0');
            }
            while (t % 2 == 0) {
                t /= 2;
            }
            if (t==1) return true;
        } while (next_permutation(s.begin(), s.end()));
        return false;
    }
};
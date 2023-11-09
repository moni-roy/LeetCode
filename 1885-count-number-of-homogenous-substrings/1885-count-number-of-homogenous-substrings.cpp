class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int count = 1, ans = 1;
        char previous = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == previous) count ++;
            else {
                count = 1;
                previous = s[i];
            }
            ans += count;
            ans %= mod;
        }
        return ans;
    }
};
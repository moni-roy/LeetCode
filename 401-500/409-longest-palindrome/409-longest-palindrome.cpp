class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for (char c : s) {
            count[c]++;
        }
        int ans = 0;
        for (int c : count) {
            ans += c / 2 * 2;
            if (ans % 2 == 0 && c % 2 == 1) {
                ans++;
            }
        }
        return ans;
    }
};
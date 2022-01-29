class Solution {
public:
    int countSubstrings(string s) {
        return usingDP(s);
        return usingExpansion(s);
    }
private:
    int usingDP(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            ans++;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans++;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                if (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2]) {
                    dp[i][i + len - 1] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
    
    int usingExpansion(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += checkPalindrome(s, i, i);
            count += checkPalindrome(s, i, i + 1);
        }
        return count;
    }
    // check the substring is palindrome or not
    int checkPalindrome(string s, int left, int right) {
        int n = s.size();
        int count = 0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};
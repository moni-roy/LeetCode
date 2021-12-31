class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s + "#" + string(s.rbegin(), s.rend());
        int n = rev.size();
        vector<int> p(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = p[i - 1];
            while (j > 0 && rev[i] != rev[j]) j = p[j - 1];
            p[i] = (rev[i] == rev[j]) ? j + 1 : j;
        }
        return string(s.rbegin(), s.rend() - p[n-1]) + s;
    }
};
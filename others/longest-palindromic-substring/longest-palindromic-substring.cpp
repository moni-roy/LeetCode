class Solution {
public:
    string longestPalindrome(string s) {
        string str = "^#";
        for (char c : s) {
            str += c;
            str += '#';
        }
        str += '$';
        int n = str.size();
        vector<int> p(n+1, 0);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            p[i] = (R > i) ? min(p[i_mirror], R - i) : 0;
            while (str[i + 1 + p[i]] == str[i - 1 - p[i]]) p[i]++;
            if (i + p[i] > R) {
                C = i;
                R = i + p[i];
            }
        }
        int max_len = 0;
        int center_index = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > max_len) {
                max_len = p[i];
                center_index = i;
            }
        }
        int start = (center_index - 1 - max_len) / 2;
        return s.substr(start, max_len);
    }
}; // O(n) manacher algorithm
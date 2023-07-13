class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        if (m > n) return -1;
        vector <int> lps = getLPS(needle);
        
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) j = lps[j-1];
                else i++;
            }
        }
        if (j == m) return i - m;

        return -1;
    }

    vector <int> getLPS(string needle) {
        int n = needle.size();
        vector <int> lps(n, 0);
        int i = 1, j = 0;
        while (i < n) {
            if (needle[i] == needle[j]) {
                lps[i] = j + 1;
                i++; j++;
            } else if (j > 0) j = lps[j - 1];
            else i++;
        }
        return lps;
    }
};
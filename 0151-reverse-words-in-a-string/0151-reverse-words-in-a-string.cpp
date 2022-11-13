class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        reverseWords(s, 0, n - 1);
        cleanSpaces(s, 0, n - 1);
        return s;
    }
    void reverseWords(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != ' ') {
                int i = l;
                while (i <= r && s[i]!=' ') i++;
                reverse(s.begin() + l, s.begin() + i);
                l = i;
            }
            else l++;
        }
    }
    void cleanSpaces(string &s, int l, int r) {
        int k = 0;
        while (l <= r) {
            if (s[l] != ' ') {
                int i = l;
                while (i <= r && s[i]!=' ') s[k++] = s[i++];
                while (i <= r && s[i] == ' ') i++;
                if (i <= r) s[k++] = ' ';
                l = i;
            }
            else l++;
        }
        s.resize(k);
    }
};
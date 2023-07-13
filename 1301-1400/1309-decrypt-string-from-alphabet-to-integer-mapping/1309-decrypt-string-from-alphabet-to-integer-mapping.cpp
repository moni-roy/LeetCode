class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int i = 0;
        while (i < s.size()) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                res += (char)((s[i] - '0') * 10 + (s[i + 1] - '0') + 'a' - 1);
                i += 3;
            } else {
                res += (char)(s[i] - '0' + 'a' - 1);
                i += 1;
            }
        }
        return res;
    }
};
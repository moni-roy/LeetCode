class Solution {
public:
    string reverseStr(string s, int k) {
        string res = "";
        for (int i = 0; i < s.size(); i += 2 * k) {
            string tmp = s.substr(i, k);
            reverse(tmp.begin(), tmp.end());
            res += tmp;
            if (i + k < s.size()) res += s.substr(i + k, k);
        }
        return res;
    }
};
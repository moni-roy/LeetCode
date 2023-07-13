class Solution {
private:
    string count(string s) {
        string res = "";
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cnt ++;
            else {
                res += to_string(cnt) + s[i - 1];
                cnt = 1;
            }
        }
        res += to_string(cnt) + s[s.size() - 1];
        return res;
    }
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            s = count(s);
        }
        return s;
    }
};
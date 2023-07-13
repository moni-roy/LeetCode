class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res;
        string ip;
        dfs(s, 0, ip, res);
        return res;
    }
private:
    void dfs(string& s, int start, string& ip, vector<string>& res) {
        if (start == s.size()) {
            if (ip.size() == s.size() + 3) res.push_back(ip);
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if (start + i > s.size()) break;
            string sub = s.substr(start, i);
            if (sub.size() > 1 && sub[0] == '0') break;
            int num = stoi(sub);
            if (num > 255) break;
            if(ip.size()) sub = "." + sub;
            ip += sub;
            dfs(s, start + i, ip, res);
            ip.erase(ip.size() - sub.size());
        }
    }
};
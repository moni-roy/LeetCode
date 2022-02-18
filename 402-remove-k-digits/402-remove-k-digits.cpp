class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        string res = "";
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && !res.empty() && res.back() > num[i]) {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        if (res.empty()) return "0";
        while (res.front() == '0' && res.size() > 1) res.erase(0, 1);
        return res;
    }
};
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        auto dfs = [&](auto&& dfs, int num, int len) -> void {
            if (len == n) {
                res.push_back(num);
                return;
            }
            int last = num % 10;
            if (last + k < 10) dfs(dfs, num * 10 + last + k, len + 1);
            if (k != 0 && last - k >= 0) dfs(dfs, num * 10 + last - k, len + 1);
        };
        if (n == 1) res.push_back(0);
        for (int i = 1; i < 10; ++i) dfs(dfs, i, 1);
        return res;
    }
};
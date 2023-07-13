class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, res);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, path, res);
            path.pop_back();
        }
    }
};
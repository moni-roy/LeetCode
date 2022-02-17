class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, path, res);
        return res;
    }
private:
    void backtracking(vector<int>& candidates, int target, int pos, vector<int> &path, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i, path, res);
            path.pop_back();
        }
    }
};
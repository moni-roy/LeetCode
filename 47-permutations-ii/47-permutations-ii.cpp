class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> uniq;
        for (int i = 0; i < nums.size(); ++i) {
            uniq[nums[i]]++;
        }
        vector<int> tmp;
        backtrack(ans, tmp, uniq, nums.size());
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, unordered_map<int, int>& uniq, int n) {
        if (tmp.size() == n) {
            ans.push_back(tmp);
            return;
        }
        for (auto& p : uniq) {
            if (p.second > 0) {
                tmp.push_back(p.first);
                uniq[p.first]--;
                backtrack(ans, tmp, uniq, n);
                uniq[p.first]++;
                tmp.pop_back();
            }
        }
    }
};
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, ans);
        return ans;
    }
    void dfs(vector<int> &nums, int index, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_map<int, int> mp;
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && mp.find(nums[i])!= mp.end())
                continue;
            mp[nums[i]] = 1;
            swap(nums[i], nums[index]);
            dfs(nums, index + 1, ans);
            swap(nums[i], nums[index]);
        }
    }
};
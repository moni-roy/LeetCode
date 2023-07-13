class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        vector<int> vs(nums.size(), 0);
        return canPartition(0, nums, k, 0, sum / k, vs);
    }
    bool canPartition(int p, vector<int> &nums, int k, int sum, int target, vector<int> &vs)
    {
        if (k == 1)
            return true;
        if (sum == target)
            return canPartition(0, nums, k - 1, 0, target, vs);
        for (int i = p; i < nums.size(); i++)
        {
            if (vs[i] == 0)
            {
                vs[i] = 1;
                if (canPartition(i + 1, nums, k, sum+nums[i], target, vs))
                    return true;
                vs[i] = 0;
            }
        }
        return false;
    }
};
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
    int rob(vector<int> &nums, int l, int r)
    {
        int prev_prev = 0, prev = 0;
        for (int i = l; i <= r; i++)
        {
            int temp = prev;
            prev = max(prev_prev + nums[i], prev);
            prev_prev = temp;
        }
        return prev;
    }
};
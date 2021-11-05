class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int max_len = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                        cnt[i] += cnt[j];
                }
            }
            if (dp[i] > max_len)
            {
                max_len = dp[i];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += (dp[i] == max_len) ? cnt[i] : 0;
        }
        return res;
    }
};
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();
        long long ans = total/n, sum = 0, idx = n - 1;
        for (int i = 0; i < n-1; i++) {
            sum += nums[i];
            long long remain = total - sum;
            long long nAns = abs(round(sum/(i+1)) - round(remain/(n-i-1)));
            if(ans >= nAns) {
                if(ans == nAns) idx = idx > i ? i : idx;
                else idx = i;
                ans = nAns;
            }
        }
        return idx;
    }
};
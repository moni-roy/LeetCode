class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        int l = 0, r = sum;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(nums, mid, m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    bool check(vector<int>& nums, int target, int m) {
        int n = nums.size();
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] > target) return false;
            if(sum + nums[i] > target) {
                sum = nums[i];
                cnt++;
            }
            else sum += nums[i];
            if(cnt > m) {
                return false;
            }
        }
        return true;
    }
};
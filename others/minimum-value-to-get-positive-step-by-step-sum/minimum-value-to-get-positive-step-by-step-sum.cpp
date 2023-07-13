class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 0, sum = 0;
        for(auto n: nums) {
            sum += n;
            ans = min(ans, sum);
        }
        return max(0, -1*ans) + 1;
    }
};
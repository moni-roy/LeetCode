class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int ans = nums.size() + 1;
        queue<int> q;
        for (auto num: nums) {
            q.push(num);
            sum += num;
            while(sum >= target) {
                ans = min(ans, (int)q.size());
                sum -= q.front();
                q.pop();
                
            }
        }
        return (ans == (nums.size() + 1)) ? 0 : ans;
    }
};
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans = 0;
        deque <int> dq;
        
        for (int i = nums.size() - 1; i >= 0; i--){
            ans = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);
            
            while (!dq.empty() && ans >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            while(! dq.empty() && (i + k) <= dq.front()) dq.pop_front();
            nums[i] = ans;
        }
        return ans;
    }
};
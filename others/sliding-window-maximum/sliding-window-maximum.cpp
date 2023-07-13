class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int>dq;
        
        for(int i = 0; i<nums.size(); i++) {
            while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            while(!dq.empty() && i >= dq.front() + k) dq.pop_front();
            if(i>=k-1) ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};
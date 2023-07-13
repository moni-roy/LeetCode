class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, cnt = 0;
        deque<int> dq;
        if(k == 0) {
            for(int n: nums) {
                if(n) cnt ++;
                else cnt = 0;
                ans = (ans < cnt) ? cnt : ans;
            }
            return ans;
        }
        for(auto n: nums) {
            if(n) {
                dq.push_back(n);
            }
            else {
                while(cnt>=k && !dq.empty()){
                    if(dq.front() == 0) cnt--;
                    dq.pop_front();
                }
                dq.push_back(n);
                cnt ++;
            }
            ans = (ans < dq.size()) ? dq.size() : ans;
        }
        return ans;
    }
};
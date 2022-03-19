class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<double> pq;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
            sum += nums[i];
        }
        double avg = sum / 2.0, cur = 0;
        int step = 0;
        while(avg > cur) {
            step++;
            double val = pq.top();
            pq.pop();
            cur += val / 2.0;
            pq.push(val / 2.0);
            if (cur >= avg) {
                break;
            }
        }
        return step;
    }
};
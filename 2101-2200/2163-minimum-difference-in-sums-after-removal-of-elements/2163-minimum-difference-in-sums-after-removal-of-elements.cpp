class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        return usingHeap(nums);
    }
private:
    long long usingHeap(vector<int> &nums) {
        int n = nums.size() / 3;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<long long> right(nums.size());
        
        long long maxSum = 0;
        // right to left, max sum of n elements
        for (int i = nums.size() - 1; i >= n; i--) {
            pq.push(nums[i]);
            maxSum += nums[i];
            if (pq.size() > n) {
                maxSum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == n) {
                right[i] = maxSum;
            }
        }

        long long ans = LLONG_MAX;
        
        // left to right, min difference
        priority_queue<int, vector<int>, less<int>> pq2;
        long long sum = 0;
        for (int i = 0; i < nums.size() - n; i++) {
            pq2.push(nums[i]);
            sum += nums[i];
            if (pq2.size() > n) {
                sum -= pq2.top();
                pq2.pop();
            }
            if (pq2.size() == n) {
                ans = min(ans, sum - right[i+1]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        int minElement = INT_MAX, ans = INT_MAX;
        for (auto num : nums) {
            if (num & 1) {
                pq.push(num * 2);
                minElement = min(minElement, num * 2);
            } else {
                pq.push(num);
                minElement = min(minElement, num);
            }
            
        }
        while (!pq.empty()) {
            int num = pq.top(); pq.pop();
            ans = min(ans, num - minElement);
            if(num & 1) break;
            else pq.push(num / 2);
            minElement = min(minElement, num / 2);
        }
        return ans;
    }
};
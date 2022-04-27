class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        // min heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], {i, 0}});
            max = max > nums[i][0] ? max : nums[i][0];
        }
        int ansX = 0, ansY = INT_MAX;
        while (pq.size() == n) {
            auto top = pq.top();
            pq.pop();
            if (ansY - ansX > max - top.first) {
                ansX = top.first;
                ansY = max;
            }
            int pos = top.second.first, idx = top.second.second;
            if (idx + 1 < nums[pos].size()) {
                pq.push({nums[pos][idx + 1], {pos, idx + 1}});
                max = max > nums[pos][idx + 1] ? max : nums[top.second.first][idx + 1];
            }
        }
        return {ansX, ansY};
    }
};
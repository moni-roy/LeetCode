class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pre(1001, 0);
        for(auto trip: trips) {
            pre[trip[1]] += trip[0];
            pre[trip[2]] -= trip[0];
        }
        int sum = 0;
        for(auto x: pre) {
            sum += x;
            if(sum > capacity) return false;
        }
        return true;
    }
};
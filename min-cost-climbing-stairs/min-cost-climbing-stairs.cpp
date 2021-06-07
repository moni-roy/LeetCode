class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n+2, 0);
        
        for(int i = n-1;i>=0;i--) {
            ans[i] = min(ans[i+1], ans[i+2]) + cost[i];
        }
        return min(ans[0], ans[1]);
    }
};
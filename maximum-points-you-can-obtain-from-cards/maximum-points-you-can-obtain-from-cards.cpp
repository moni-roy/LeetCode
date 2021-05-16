class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> preSum(n+2, 0);
        for(int i = 1; i<=n; i++) {
            preSum[i] = preSum[i-1] + cardPoints[i-1];
        }
        int w = n - k;
        int l = 1, h = w;
        int ans = 0;
        while(h<=n) {
            ans = max(ans, preSum[n] - preSum[h] + preSum[l-1]);
            l++;
            h++;
        }
        return ans;
    }
};
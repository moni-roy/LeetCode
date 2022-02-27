class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) { 
        // pre-processing
        int maxLap = 0;
        vector<long long> bestLap(30 + 1, LONG_LONG_MAX);
        for(auto tire : tires) {
            long long F = tire[0];
            long long R = tire[1];
            long long cost = 0;
            for(int i = 1; i <= 30 && F < INT_MAX; i++) {
                cost += F;
                bestLap[i] = min(bestLap[i], cost);
                F *= R;
                maxLap = max(maxLap, i);
            }
        }

        // dp
        vector<long long> dp(numLaps + 1, LONG_LONG_MAX);
        dp[0] = -changeTime;
        for(int i = 1; i <= numLaps; i++) {
            for(int j = 1; j <= maxLap && j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j] + bestLap[j] + changeTime);
            }
        }
        // cout<<"OK"<<endl;
        return dp[numLaps];
    }
};
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int max_val = 0;
        for (int i = 0; i < values.size(); ++i) {
            ans = max(ans, max_val + values[i]);
            max_val = max(max_val, values[i]) - 1;
        }
        return ans;
    }
};
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> max_ranges(n + 1);
        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            max_ranges[start] = max(max_ranges[start], end);
        }
        int ans = 0, currEnd = 0, nextEnd = 0;
        for(int i = 0; i <= n; i++) {
            if (i > nextEnd) return -1;
            if (i > currEnd){
                ans++;
                currEnd = nextEnd;
            }
            nextEnd = max(nextEnd, max_ranges[i]);
        }
        return ans;
    }
};
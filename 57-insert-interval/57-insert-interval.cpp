class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        if (n == 0) {
            res.push_back(newInterval);
            return res;
        }
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        if (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
        }
        res.push_back(newInterval);
        int last = newInterval[1];
        while (i < n) {
            if (intervals[i][0] > last) {
                res.push_back(intervals[i]);
            }
            else {
                last = max(last, intervals[i][1]);
                res.back()[1] = last;
            }
            i++;
        }
        return res;
    }
};
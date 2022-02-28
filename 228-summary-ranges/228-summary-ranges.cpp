class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        vector<string> res;
        int curIdx = 0;

        while (curIdx < n) {
            int start = nums[curIdx];
            int end = start;
            while (curIdx < n - 1 && nums[curIdx + 1] == end + 1) {
                end++;
                curIdx++;
            }
            if (start == end) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(end));
            }
            curIdx++;
        }
        return res;
    }
};
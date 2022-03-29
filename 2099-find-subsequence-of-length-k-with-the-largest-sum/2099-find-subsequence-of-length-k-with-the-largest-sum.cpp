class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector <pair <int, int>> numsWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndex.push_back(make_pair(nums[i], i));
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());
        vector <pair <int, int>> result;
        for (int i = numsWithIndex.size() - 1; i >= 0; i--) {
            if (result.size() < k) {
                result.push_back(numsWithIndex[i]);
            } else {
                break;
            }
        }
        vector <int> res;
        sort(result.begin(), result.end(), [](pair <int, int> a, pair <int, int> b) {
            return a.second < b.second;
        });
        for (int i = 0; i < result.size(); i++) {
            res.push_back(result[i].first);
        }
        return res;
    }
};
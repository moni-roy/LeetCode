class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // quick select to find k top frequent elements
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        vector<int> res;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            res.push_back(it->first);
        }
        int l = 0, r = res.size() - 1;
        while (l < r) {
            int m = partition(res, l, r, freq);
            if (m == k - 1) break;
            else if (m < k - 1) l = m + 1;
            else r = m - 1;
        }
        return vector<int>(res.begin(), res.begin() + k);
    } // time complexity: O(n)
    int partition(vector<int>& nums, int l, int r, unordered_map<int, int>& freq) {
        int pivot = freq[nums[r]];
        int i = l;
        for (int j = l; j < r; j++) {
            if (freq[nums[j]] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
};
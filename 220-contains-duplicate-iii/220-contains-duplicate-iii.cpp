class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        return containsNearbyAlmostDuplicateUsingBucket(nums, k, t);
    }
private:
    bool containsNearbyAlmostDuplicateUsingBST(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        int n = nums.size();
        multiset<long long> bst;
        for (int i = 0; i < n; i++) {
            auto it = bst.lower_bound(0LL + nums[i] - t);
            if (it != bst.end() && *it - nums[i] <= t) return true;
            if (i >= k) bst.erase(bst.find(nums[i - k]));
            bst.insert(nums[i]);
        }
        return false;
    }
    bool containsNearbyAlmostDuplicateUsingBucket(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        int n = nums.size();
        unordered_map<long long, long long> bucket;

        auto getIdx = [&](long long x) {
            long long idx = x / (1LL + t);
            if (x < 0) idx--;
            return idx;
        };

        for (int i = 0; i < n; i++) {
            int idx = getIdx(nums[i]);
            if (bucket.find(idx) != bucket.end()) return true;
            if (bucket.find(idx - 1) != bucket.end() && nums[i] - bucket[idx - 1] <= t) return true;
            if (bucket.find(idx + 1) != bucket.end() && bucket[idx + 1] - nums[i] <= t) return true;
            bucket[idx] = nums[i];
            if (i >= k) bucket.erase(bucket.find(getIdx(nums[i - k])));
        }
        return false;
    }
};
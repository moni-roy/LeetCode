class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        return containsNearbyAlmostDuplicateUsingBST(nums, k, t);
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
};
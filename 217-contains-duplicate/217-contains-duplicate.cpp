class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return containsDuplicateUsingSet(nums);
    }
private:
    bool containsDuplicateUsingSet(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int i = 0; i < nums.size(); i++) {
            if (hashSet.find(nums[i]) != hashSet.end()) {
                return true;
            }
            hashSet.insert(nums[i]);
        }
        return false;
    }
};
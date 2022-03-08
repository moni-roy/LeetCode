class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return containsDuplicateUsingMap(nums);
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
    
    bool containsDuplicateUsingMap(vector<int>& nums) {
        unordered_map<int, int> mapCount;
        for(auto num: nums) {
            mapCount[num] ++;
            if(mapCount[num] == 2) return true;
        }
        return false;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        return usingHashSet(nums);
    }
private:
    int usingHashSet(vector<int> &nums) {
        int maxPrefix = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            unordered_set<int> prefixes;
            mask = mask | (1 << i);
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            int currPrefix = maxPrefix | (1 << i);
            for (int prefix : prefixes) {
                if (prefixes.count(currPrefix ^ prefix)) {
                    maxPrefix = currPrefix;
                    break;
                }
            }
        }
        return maxPrefix;
    }
};
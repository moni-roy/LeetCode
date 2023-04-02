class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for (auto x : spells) {
            int ret = binarySearch(potions, x, success);
            ans.push_back(ret);
        }
        return ans;
    }
private:
    int binarySearch(vector<int>& potions, long long x, long long success) {
        int l = 0, r = potions.size() - 1;
        int ret = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (success - x * potions[mid] > 0) {
                ret = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return potions.size() - ret;
    }
};
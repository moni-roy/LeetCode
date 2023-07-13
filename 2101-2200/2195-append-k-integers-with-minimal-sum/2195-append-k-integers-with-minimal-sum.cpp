class Solution {
public:
    long long minimalKSum(vector<int> &nums, int K) {
        long long k = K;
        long long res = k * (k + 1) / 2;
        // copy and unique
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

        for(auto &n : nums2) {
            if( n <= k){
                res += (k + 1 - n);
                k ++;
            }
        }
        return res;
    }
};

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        // get divisors
        vector<long long> divisors;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                divisors.push_back(i);
                if (i * i != k) {
                    divisors.push_back(k / i);
                }
            }
        }
        unordered_map<int, int> freq;
        // count pairs
        long long result = 0;
        for(auto num: nums) {
            int gcd = __gcd(num, k);
            for(auto div: divisors) {
                result += gcd * div % k == 0 ? freq[ div] : 0;
            }
            freq[gcd]++;
        }
        return result;
    }
};

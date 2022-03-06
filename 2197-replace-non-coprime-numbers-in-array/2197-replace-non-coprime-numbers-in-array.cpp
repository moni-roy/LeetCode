class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(auto num: nums) {
            long long lcm = num;
            while(res.size()) {
                long long n = res.back();
                if(__gcd(lcm, n) == 1) break;
                res.pop_back();
                lcm = lcm * n / __gcd(lcm, n);
            }
            res.push_back(lcm);
        }
        return res;
    }
};
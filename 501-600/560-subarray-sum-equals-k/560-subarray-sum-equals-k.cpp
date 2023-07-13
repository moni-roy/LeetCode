class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        long long sum = 0;
        unordered_map<long long, int> freq;
        for(auto num : nums) {
            sum += num;
            if(sum == k) count++;
            if(freq.find(sum - k) != freq.end()) count += freq[sum - k];
            freq[sum]++;
        }
        return count;
    }
};
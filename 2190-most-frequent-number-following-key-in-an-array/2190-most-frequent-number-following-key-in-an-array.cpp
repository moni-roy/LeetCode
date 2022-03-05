class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int cnt = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == key) {
                freq[nums[i + 1]]++;
            }
        }
        int ans = 0;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            if(it->second > cnt) {
                cnt = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};
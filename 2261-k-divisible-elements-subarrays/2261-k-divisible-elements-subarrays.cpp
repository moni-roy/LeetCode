class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_map<string, bool> exist;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            string s = "";
            for(int j = i; j < nums.size(); j++) {
                if (nums[j] % p == 0) {
                    count++;
                }
                if(count > k) break;
                s += "$" + to_string(nums[j]);
                if (exist.find(s) == exist.end()) res++;
                exist[s] = true;
            }
        }
        return res;
    }
};
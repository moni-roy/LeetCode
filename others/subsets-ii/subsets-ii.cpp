class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        sort(nums.begin(), nums.end());
        int s = 0;
        for(int i = 0; i< nums.size();) {
            int cnt = 0;
            while(cnt + i < nums.size() && nums[i+cnt] == nums[i]) cnt++;
            int sz = ret.size();
            for(int j = 0; j < sz; j++) {
                auto pre = ret[j];
                for(int k = 0; k<cnt; k++) {
                    pre.push_back(nums[i]);
                    ret.push_back(pre);
                }
            }
            i += cnt;
        }
        return ret;
    }
};
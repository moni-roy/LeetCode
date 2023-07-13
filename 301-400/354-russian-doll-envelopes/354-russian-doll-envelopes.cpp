class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        if(v.empty()) return  0;
        sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp;
        for(auto& vv : v){
            auto it = lower_bound(dp.begin(), dp.end(), vv[1]);
            if(it == dp.end()) dp.push_back(vv[1]);
            else *it = vv[1];
        }
        return dp.size();
    }
};
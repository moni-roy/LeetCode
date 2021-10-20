class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0]<b[0];
        });
        
        vector<vector<int> > ret;
        
        for(auto x: intervals) {
            if(ret.empty() || ret.back()[1] < x[0]) ret.push_back(x);
            else {
                ret.back()[1] = max(ret.back()[1], x[1]);
            }
        }
        return ret;
    }
};
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int> > parTime;
        for (int i = 0; i < plantTime.size(); i++) {
            parTime.push_back({plantTime[i], growTime[i]});
        }
        sort(parTime.begin(), parTime.end(), [](pair<int, int> a, pair<int, int>b) {
           return a.second>b.second; 
        });
        
        int ans = 0, cur = 0;
        for(auto p: parTime) {
            cur += p.first;
            ans = max(ans, cur + p.second);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int>ans;
        ans.push_back(1);
        while(ans.size() < n) {
            vector<int> t;
            for(auto a: ans) if(a*2-1 <= n) t.push_back(a*2-1);
            for(auto a: ans) if(a*2 <= n) t.push_back(a*2);
            ans = t;
        }
        return ans;
    }
};
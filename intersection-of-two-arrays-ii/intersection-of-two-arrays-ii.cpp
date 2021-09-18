class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        vector<int> ans;
        map<int, int> mp;
        for(auto x: n1) mp[x]++;
        for(auto x: n2) {
            if(mp[x]){
                mp[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};
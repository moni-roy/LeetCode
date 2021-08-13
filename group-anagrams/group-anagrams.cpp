class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>>mp;
        for(auto s: strs) {
            string cs = s;
            sort(s.begin(), s.end());
            mp[s].push_back(cs);
        }
        vector<vector<string> > ret;
        for(auto it: mp) {
            ret.push_back(it.second);
        }
        return ret;
    }
};
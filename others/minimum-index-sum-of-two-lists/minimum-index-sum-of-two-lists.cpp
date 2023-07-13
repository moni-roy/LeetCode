class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1, map2;
        unordered_map<int, vector<string>> map3;
        for (int i = 0; i < list1.size(); ++i) map1[list1[i]] = i;
        for (int i = 0; i < list2.size(); ++i) map2[list2[i]] = i;
        int mn = INT_MAX;
        for (auto& p : map1) {
            if (map2.count(p.first)) {
                mn = min(mn, p.second + map2[p.first]);
                map3[p.second + map2[p.first]].push_back(p.first);
            }
        }
        return map3[mn];      
    }
};
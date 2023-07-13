class Solution {
public:
    int countPoints(string rings) {
        return usingHashMap(rings);
    }
private:
    int usingHashMap(string &rings) {
        unordered_map<char, unordered_set<char>> map;
        int n = rings.size();
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            map[rings[i + 1]].insert(rings[i]);
        }
        for(char c = '0'; c <= '9'; c++) {
            if (map.find(c) == map.end()) continue;
            if(map[c].size() == 3) res ++;
        }
        return res;
    }
};
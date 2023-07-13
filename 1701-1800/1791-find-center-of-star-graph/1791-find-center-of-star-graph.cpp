class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> deg;
        for(auto edge: edges) {
            deg[edge[0]] ++;
            deg[edge[1]] ++;
        }
        for(auto it: deg) {
            if(it.second == edges.size()) return it.first;
        }
        return 1;
    }
};
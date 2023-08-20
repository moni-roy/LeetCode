class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)  group[i] = m++;
        }
        vector<unordered_set<int> > groups(m), nodes(n);
        vector<int> group_degree(m, 0), node_degree(n, 0);

        for (int x = 0; x < n; x++) {
            int group_x = group[x];
            for (auto y : beforeItems[x]) {
                int group_y = group[y];
                if (group_x != group_y && !groups[group_y].count(group_x)) {
                    groups[group_y].insert(group_x);
                    group_degree[group_x]++;
                }
                if (!nodes[y].count(x)) {
                    nodes[y].insert(x);
                    node_degree[x]++;
                }
            }
        }
        vector<int> groups_order = topSort(groups, group_degree);
        vector<int> nodes_order = topSort(nodes, node_degree);

        vector <vector<int> > nodes_groups_order(m);
        for (auto x : nodes_order) {
            nodes_groups_order[group[x]].push_back(x);
        }
        vector<int> ans;
        for (auto x: groups_order) {
            for (auto y: nodes_groups_order[x]) {
                ans.push_back(y);
            }
        }
        return ans;
    }
private:
    vector<int> topSort(vector<unordered_set<int> > &nodes, vector<int> &degree) {
        int n = nodes.size();
        vector<int> ans;
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            ans.push_back(x);
            for (auto y : nodes[x]) {
                degree[y]--;
                if (degree[y] == 0) que.push(y);
            }
        }
        return ans.size() == n ? ans : vector<int>();
        
    }
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        // visited is used to record the state of each node
        vector<vector<bool>> visited(n, vector<bool>( 1 << n, false));
        // queue for BFS
        queue<pair<int, int>> q;
        // start from each node
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        int steps = 0;
        // BFS
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) { // for each node
                auto [node, state] = q.front();
                q.pop();
                for(auto next: graph[node]) { // for each neighbor
                    int next_state = state | (1 << next); // update state
                    if(next_state == (1 << n) - 1) return steps + 1; // all nodes are visited

                    if(!visited[next][next_state]) { // if not visited
                        q.push({next, next_state});
                        visited[next][next_state] = true;
                    }
                }
            }
            ++steps; // update steps
        }
        return 0;
    }
};
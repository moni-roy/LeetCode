class Graph {
private:
vector<vector<pair<int, int> > > graph;
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (auto &edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // dijkstra path
        int n = graph.size();
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        vector<int> shortest(n, INT_MAX);
        shortest[node1] = 0;
        pq.push({0, node1});
        while(pq.size()) {
            auto v = pq.top(); pq.pop();
            int currNode = v[1];
            int currCost = v[0];
            if (currCost > shortest[currNode]) continue;
            if (currNode == node2) return currCost;
            for (auto &edge: graph[currNode]) {
                int nextNode = edge.first;
                int cost = edge.second + currCost;
                if (cost < shortest[nextNode]) {
                    shortest[nextNode] = cost;
                    pq.push({cost, nextNode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
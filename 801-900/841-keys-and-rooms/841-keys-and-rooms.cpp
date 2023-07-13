class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, 0, visited);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, int cur, vector<bool>& visited) {
        visited[cur] = true;
        for (int next : rooms[cur]) {
            if (!visited[next]) dfs(rooms, next, visited);
        }
    }
};
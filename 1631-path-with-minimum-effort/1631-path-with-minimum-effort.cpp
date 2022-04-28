class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // using Binary search and dfs 
        int low = 0, high = 1e6;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(heights, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
private:
    bool check(vector<vector<int>>& heights, int target) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(heights, visited, 0, 0, target);
    }
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<int>>& heights,
        vector<vector<bool>>& visited, int i, int j, int target) {
        if(i == heights.size() - 1 && j == heights[0].size() - 1) return true;

        visited[i][j] = true;
        for (auto& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() &&
                !visited[x][y]) {
                // check diff between current height and new height
                int diff = abs(heights[i][j] - heights[x][y]);
                if (diff <= target) {
                    if (dfs(heights, visited, x, y, target)) return true;
                }
            }
        }
        return false;
    }
};
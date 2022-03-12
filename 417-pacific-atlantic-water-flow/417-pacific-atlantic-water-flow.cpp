class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j, int m, int n) {
        visited[i][j] = 1;
        if(j - 1 >= 0 && heights[i][j - 1] >= heights[i][j] && visited[i][j - 1] == 0) {
             dfs(heights, visited, i, j - 1, m, n);
        }
        if(j + 1 < n && heights[i][j + 1] >= heights[i][j] && visited[i][j + 1] == 0) {
             dfs(heights, visited, i, j + 1, m, n);
        }
        if(i - 1 >= 0 && heights[i - 1][j] >= heights[i][j] && visited[i - 1][j] == 0) {
             dfs(heights, visited, i - 1, j, m, n);
        }
        if(i + 1 < m && heights[i + 1][j] >= heights[i][j] && visited[i + 1][j] == 0) {
             dfs(heights, visited, i + 1, j, m, n);
        }
    }
};
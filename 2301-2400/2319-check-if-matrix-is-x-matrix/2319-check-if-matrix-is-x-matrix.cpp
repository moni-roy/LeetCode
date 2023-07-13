class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        
        for (int i = 0, j = 0; i < grid.size(); i++, j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }

        for (int i = 0, j = grid[0].size() - 1; i < grid.size(); i++, j--) {
            if (grid[i][j] == 0) {
                return false;
            }
            grid[i][j] = 0;
        }

        for (int i = 0, j = 0; i < grid.size(); i++, j++) {
            grid[i][j] = 0;
        }

        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
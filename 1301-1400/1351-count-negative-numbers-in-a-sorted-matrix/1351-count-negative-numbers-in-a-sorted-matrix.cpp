class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size(), res = 0;
        int row = m - 1, col = 0;
		while (row >= 0 && col < n) {
			if (grid[row][col] < 0) {
				res += n - col;
				row--;
			} else {
				col++;
			}
		}
		return res;
    }
};
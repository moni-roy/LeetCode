class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
		// make a single vector
		vector<int> v;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				v.push_back(grid[i][j]);
			}
		}
		// shift the vector last to first
		for (int i = 0; i < k; i++) {
			int last = v.back();
			v.erase(v.end() - 1);
			v.insert(v.begin(), last);
		}
		// make a new grid
		vector<vector<int>> ans;
		for (int i = 0; i < m; i++) {
			vector<int> row;
			for (int j = 0; j < n; j++) {
				row.push_back(v[i * n + j]);
			}
			ans.push_back(row);
		}
		return ans;
    }
};
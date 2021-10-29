class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 2) {
					q.push(make_pair(i, j));
				}
			}
		}
		int ans = 0;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (x - 1 >= 0 && grid[x - 1][y] == 1) {
					grid[x - 1][y] = 2;
					q.push(make_pair(x - 1, y));
				}
				if (x + 1 < m && grid[x + 1][y] == 1) {
					grid[x + 1][y] = 2;
					q.push(make_pair(x + 1, y));
				}
				if (y - 1 >= 0 && grid[x][y - 1] == 1) {
					grid[x][y - 1] = 2;
					q.push(make_pair(x, y - 1));
				}
				if (y + 1 < n && grid[x][y + 1] == 1) {
					grid[x][y + 1] = 2;
					q.push(make_pair(x, y + 1));
				}
			}
			ans++;
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) return -1;
			}
		}
	return max(0, ans - 1);
	}
};
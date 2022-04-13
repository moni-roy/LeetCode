class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int i = 0, j = 0, k = 1;
		while (k <= n * n) {
			while (j < n && res[i][j] == 0) {
				res[i][j] = k++;
				j++;
			}
			j--;
			i++;
			while (i < n && res[i][j] == 0) {
				res[i][j] = k++;
				i++;
			}
			i--;
			j--;
			while (j >= 0 && res[i][j] == 0) {
				res[i][j] = k++;
				j--;
			}
			j++;
			i--;
			while (i >= 0 && res[i][j] == 0) {
				res[i][j] = k++;
				i--;
			}
			i++;
			j++;
		}
		return res;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal(rowIndex + 1, vector<int>(rowIndex + 1, 0));
        pascal[0][0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    pascal[i][j] = 1;
                } else {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
        }
        return pascal[rowIndex];
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res;
        if (mat.size() == 0 || mat[0].size() == 0) {
            return res;
        }
        if (mat.size() * mat[0].size() != r * c) {
            return mat;
        }
        res.resize(r);
        for (int i = 0; i < r; i++) {
            res[i].resize(c);
        }
        int row = 0, col = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                res[row][col] = mat[i][j];
                col++;
                if (col == c) {
                    col = 0;
                    row++;
                }
            }
        }
        return res;
    }
};
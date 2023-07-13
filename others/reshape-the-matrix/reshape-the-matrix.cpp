class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int R = mat.size(), C = mat[0].size();
    if (R * C != r * c) return mat;
    vector<int> oneDimension(R * C);
    int id = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        oneDimension[id++] = mat[i][j];
      }
    }
    vector<vector<int> > ret;
    for (int i = 0; i < r; i++) {
      vector<int> row;
      for (int j = 0; j < c; j++) {
        row.push_back(oneDimension[i * c + j]);
      }
      ret.push_back(row);
    }
    return ret;
  }
};
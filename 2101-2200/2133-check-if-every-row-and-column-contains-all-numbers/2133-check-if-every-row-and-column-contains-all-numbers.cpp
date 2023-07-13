class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            vector<int> tmp;
            for(int j = 0; j < m; j++) {
                tmp.push_back(matrix[i][j]);
            }
            sort(tmp.begin(), tmp.end());
            for(int j = 0; j < m; j++) {
                if(tmp[j] != j+1) {
                    return false;
                }
            }
        }
        for(int j = 0; j < m; j++) {
            vector<int> tmp;
            for(int i = 0; i < n; i++) {
                tmp.push_back(matrix[i][j]);
            }
            sort(tmp.begin(), tmp.end());
            for(int i = 0; i < n; i++) {
                if(tmp[i] != i+1) {
                    return false;
                }
            }
        }
        return true;
    }
};
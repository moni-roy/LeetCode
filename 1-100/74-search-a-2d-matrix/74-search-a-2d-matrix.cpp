class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ri = 0, ci = matrix[0].size() - 1;
        while (ri < matrix.size() && ci >= 0) {
            if (matrix[ri][ci] == target) return true;
            else if (matrix[ri][ci] > target) ci--;
            else ri++;
        }
        return false;
    }
};
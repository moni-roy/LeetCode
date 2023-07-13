class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowVis(9, vector<int>(9, 0));
        vector<vector<int>> colVis(9, vector<int>(9, 0));
        vector<vector<int>> subVis(9, vector<int>(9, 0));
        
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++) {
                if(board[r][c] != '.') {
                    int num = board[r][c] - '0' - 1;
                    int sub = r / 3 * 3 + c / 3;
                    if(rowVis[r][num] || colVis[c][num] || subVis[sub][num]) 
                        return false;
                    rowVis[r][num] = colVis[c][num] = subVis[sub][num] = 1;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> queens(n, string(n,'.'));
        backTracking(ans, queens, 0, n);
        return ans;
    }
    void backTracking(vector<vector<string> > &ans, vector<string> &queens, int rw, int n) {
        if(rw == n) {
            ans.push_back(queens);
        }
        for(int c = 0; c < n; c++) {
            if(valid(queens, rw, c, n)) {
                queens[rw][c] = 'Q';
                backTracking(ans, queens, rw+1, n);
                queens[rw][c] = '.';
            }
        }
    }
    
    bool valid(vector<string> &queens, int r, int c, int n) {
        for(int i = 0; i < r; i ++ ) {
            if(queens[i][c] == 'Q') return false;
        }
        for(int i = r-1, j = c-1; i>=0 && j>=0; i--, j--){
            if(queens[i][j]=='Q') return false;
        }
        for(int i = r-1, j=c+1; i>=0 && j<n;i--, j++) {
            if(queens[i][j]=='Q') return false;
        }
        return true;
    }
};
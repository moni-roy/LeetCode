class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int> > res(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int ones = check(i, j, board);
                if(ones < 2 || ones > 3) {
                    res[i][j] = 0;
                }
                else if(ones == 3) {
                    res[i][j] = 1;
                }
                else res[i][j] = board[i][j];
            }
        }
        board = res;
    }
private:
    int dx[8] = {1, 1, 0, 0, -1, -1, 1, -1};
    int dy[8] = {0, -1, 1, -1, 0, 1, 1, -1};
    
    int check(int x, int y, vector<vector<int> > &board) {
        int res = 0;
        for(int i = 0;  i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()) {
                res += board[xx][yy];
            }
        }
        return res;
    }
};
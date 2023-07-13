class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        withoutExtraSpace(board);
        // usingExtraMemory(board);
    }
private:
    void withoutExtraSpace(vector<vector<int> >& board) {
        
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int lives = 0;

                for(int x = max(0, i - 1); x <= min(m - 1, i + 1); x ++) {
                    for (int y = max(0, j - 1); y <= min(n - 1, j + 1); y++) {
                        if(x == i && y == j) continue;
                        if(abs(board[x][y]) == 1) lives++;
                    }
                }

                if(board[i][j] == 1 && (lives < 2 || lives > 3)) board[i][j] = -1;
                if(board[i][j] == 0 && lives == 3) board[i][j] = 2;
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }

    int dx[8] = {1, 1, 0, 0, -1, -1, 1, -1};
    int dy[8] = {0, -1, 1, -1, 0, 1, 1, -1};
    
    void usingExtraMemory(vector<vector<int>>& board) {
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
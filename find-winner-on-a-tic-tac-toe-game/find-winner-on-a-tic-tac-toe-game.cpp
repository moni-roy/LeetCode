class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        vector<vector<int>> board(3, vector<int>(3, 0));
        int pl = 1;
        for (auto m : moves)
        {

            board[m[0]][m[1]] = pl;
            if (board_fill(board, pl))
            {
                if (pl == 1)
                    return "A";
                else
                    return "B";
            }

            pl *= -1;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
    bool board_fill(vector<vector<int>> &board, int pl)
    {
        return (row_fill(board, pl) || col_fill(board, pl) || dig_fill(board, pl));
    }
    bool row_fill(vector<vector<int>> &board, int pl)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == pl)
                return true;
        }
        return false;
    }

    bool col_fill(vector<vector<int>> &board, int pl)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == pl)
                return true;
        }
        return false;
    }

    bool dig_fill(vector<vector<int>> &board, int pl)
    {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == pl)
            return true;

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == pl)
            return true;

        return false;
    }
};
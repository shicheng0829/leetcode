class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
                    helper(board, i, j);
            }
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
    void helper(vector<vector<char>> &board, int i, int j)
    {
        int row = board.size();
        int col = board[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col)
            return;
        if (board[i][j] == 'O')
        {
            board[i][j] = '1';
            helper(board, i - 1, j);
            helper(board, i + 1, j);
            helper(board, i, j - 1);
            helper(board, i, j + 1);
        }
    }
};
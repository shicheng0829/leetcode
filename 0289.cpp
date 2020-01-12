class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> vec = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        if (board.empty())
            return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int count = 0;
                for (int k = 0; k < vec.size(); ++k)
                {
                    if (i + vec[k][0] >= 0 && i + vec[k][0] < row && j + vec[k][1] >= 0 && j + vec[k][1] < col &&
                        board[i + vec[k][0]][j + vec[k][1]] & 1 == 1)
                        ++count;
                }
                if ((board[i][j] & 1) == 1)
                {
                    if (count < 2)
                        continue;
                    else if (count == 2 || count == 3)
                        board[i][j] = board[i][j] | 2;
                    else if (count > 3)
                        continue;
                }
                else if ((board[i][j] & 1) == 0)
                {
                    if (count == 3)
                    {
                        board[i][j] = board[i][j] | 2;
                    }
                }
            }
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                board[i][j] = board[i][j] >> 1;
    }
};
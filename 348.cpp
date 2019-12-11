class TicTacToe
{
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        anti_diagonal = 0;
        size = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        if (player == 1)
        {
            rows[row]++;
            cols[col]++;
            if (row == col)
                diagonal++;
            if (row + col == size - 1)
                anti_diagonal++;
        }
        else if (player == 2)
        {
            rows[row]--;
            cols[col]--;
            if (row == col)
                diagonal--;
            if (row + col == size - 1)
                anti_diagonal--;
        }
        if (rows[row] == size || cols[col] == size || diagonal == size || anti_diagonal == size)
            return 1;
        else if (rows[row] == -size || cols[col] == -size || diagonal == -size || anti_diagonal == -size)
            return 2;
        return 0;
    }

private:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti_diagonal;
    int size;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
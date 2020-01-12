class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<int>> row(9, unordered_set<int>{});
        vector<unordered_set<int>> col(9, unordered_set<int>{});
        vector<unordered_set<int>> box(9, unordered_set<int>{});
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == '.')
                    continue;
                int cur = board[i][j] - '0';
                int box_index = i / 3 * 3 + j / 3;
                if (row[i].find(cur) != row[i].end() || col[j].find(cur) != col[j].end() || box[box_index].find(cur) != box[box_index].end())
                    return false;
                row[i].insert(cur);
                col[j].insert(cur);
                box[box_index].insert(cur);
            }
        }
        return true;
    }
};
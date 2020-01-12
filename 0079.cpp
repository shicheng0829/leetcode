class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (helper(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>> &board, string &word, int begin, int i, int j, vector<vector<int>> &visited)
    {
        if (begin == word.size())
        {
            return true;
        }
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
            return false;
        if (begin >= word.size())
            return false;
        if (visited[i][j] == 1 || board[i][j] != word[begin])
            return false;
        visited[i][j] = 1;
        bool res = helper(board, word, begin + 1, i, j + 1, visited) ||
                   helper(board, word, begin + 1, i, j - 1, visited) ||
                   helper(board, word, begin + 1, i + 1, j, visited) ||
                   helper(board, word, begin + 1, i - 1, j, visited);
        visited[i][j] = 0;
        return res;
    }
};
class Solution
{
public:
    vector<vector<int>> step = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int row, col;
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return 0;
        row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int res = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                res = max(res, dfs(matrix, i, j, dp));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
    {
        if (dp[i][j] != 0)
            return dp[i][j];
        for (auto &p : step)
        {
            int next_i = i + p[0], next_j = j + p[1];
            if (next_i >= 0 && next_i < row && next_j >= 0 && next_j < col && matrix[i][j] < matrix[next_i][next_j])
            {
                dp[i][j] = max(dp[i][j], dfs(matrix, next_i, next_j, dp));
            }
        }
        return ++dp[i][j];
    }
};
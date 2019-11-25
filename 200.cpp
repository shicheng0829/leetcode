class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int r = grid.size(), c = grid[0].size();
        int res = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == '1')
                    ++res;
                helper(grid, i, j);
            }
        }
        return res;
    }
    void helper(vector<vector<char>> &grid, int i, int j)
    {
        int r = grid.size(), c = grid[0].size();
        if (i >= r || i < 0 || j >= c || j < 0 || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        helper(grid, i + 1, j);
        helper(grid, i - 1, j);
        helper(grid, i, j + 1);
        helper(grid, i, j - 1);
    }
};
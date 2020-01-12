class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int r = matrix.size(), c = matrix[0].size();
        int i = 0, j = c - 1;
        while (i < r && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int R = matrix.size() - 1, C = matrix[0].size() - 1;
        bool isRow = false, isCol = false;
        for (int i = 0; i <= R; ++i)
        {
            for (int j = 0; j <= C; ++j)
            {
                if (i == 0 && matrix[i][j] == 0)
                {
                    isRow = true;
                }
                if (j == 0 && matrix[i][j] == 0)
                {
                    isCol = true;
                }
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i <= R; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j <= C; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j <= C; ++j)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i <= R; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isRow)
        {
            for (int j = 0; j <= C; ++j)
            {
                matrix[0][j] = 0;
            }
        }
        if (isCol)
        {
            for (int i = 0; i <= R; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
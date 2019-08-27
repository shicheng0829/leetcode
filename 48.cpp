class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        //对角线翻转
        for (int i = 0; i < row; ++i)
        {
            for (int j = i; j < col; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //左右翻转
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col / 2; ++j)
            {
                swap(matrix[i][j] , matrix[i][col - 1 - j]);
            }
        }
    }
};
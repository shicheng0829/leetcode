class NumMatrix
{
public:
    vector<vector<int>> data;
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> &matrix)
    {
        data = matrix;
        if (matrix.empty())
            return;
        sum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < data.size(); ++i)
        {
            sum[i][0] = data[i][0];
            for (int j = 1; j < data[0].size(); ++j)
            {
                sum[i][j] = sum[i][j - 1] + data[i][j];
            }
        }
    }

    void update(int row, int col, int val)
    {
        data[row][col] = val;
        sum[row][0] = data[row][0];
        for (int j = 1; j < data[0].size(); ++j)
        {
            sum[row][j] = sum[row][j - 1] + data[row][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        for (int i = row1; i <= row2; ++i)
        {
            if (col1 == 0)
                res += sum[i][col2];
            else
                res += sum[i][col2] - sum[i][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
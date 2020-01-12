class Solution
{
public:
    int findBlackPixel(vector<vector<char>> &picture, int N)
    {
        int row = picture.size(), col = picture[0].size();
        vector<int> rows(row, 0);
        vector<int> cols(col, 0);
        // 列号-> 黑色像素行号
        vector<vector<int>> black_rows(col, vector<int>{});
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (picture[i][j] == 'B')
                {
                    rows[i]++;
                    cols[j]++;
                    black_rows[j].push_back(i);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (picture[i][j] == 'B' && rows[i] == N && cols[j] == N)
                {
                    bool match = true;
                    for (int k = 0; k < black_rows[j].size(); ++k)
                    {
                        if (picture[i] != picture[black_rows[j][k]])
                        {
                            match = false;
                            break;
                        }
                    }
                    if (match)
                        res++;
                }
            }
        }

        return res;
    }
};
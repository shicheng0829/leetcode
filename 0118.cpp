class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        res.push_back(vector<int>{1});
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> layer;
            layer.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                layer.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            layer.push_back(1);
            res.push_back(layer);
        }
        return res;
    }
};
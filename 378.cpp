class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        auto cmp = [](vector<int> left, vector<int> right) { return left[0] > right[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < matrix.size(); ++i)
            pq.push(vector<int>{matrix[i][0], i, 0});
        for (int i = 0; i < k - 1; ++i)
        {
            vector<int> p = pq.top();
            pq.pop();
            if (p[2] + 1 < matrix[0].size())
                pq.push(vector<int>{matrix[p[1]][p[2] + 1], p[1], p[2] + 1});
        }
        return pq.top()[0];
    }
};
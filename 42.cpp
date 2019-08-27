class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            right[i] = max(right[i + 1], height[i]);
        }
        int cnt = 0;
        for (int i = 1; i <= n - 2; ++i)
        {
            cnt += min(right[i], left[i]) - height[i];
        }
        return cnt;
    }
};
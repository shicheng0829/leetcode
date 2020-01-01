class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int overlap = 0;
            int cur = 0;
            unordered_map<string, int> mp;
            for (int j = i + 1; j < n; ++j)
            {
                int y = points[i][1] - points[j][1];
                int x = points[i][0] - points[j][0];
                if (x == y && x == 0)
                {
                    overlap++;
                    continue;
                }
                int factor = gcd(x, y);
                string k = to_string(y / factor) + to_string(x / factor);
                mp[k]++;
                cur = max(cur, mp[k]);
            }
            res = max(res, cur + overlap + 1);
        }
        return res;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
};
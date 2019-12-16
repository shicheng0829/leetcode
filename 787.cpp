//Bellman-Ford
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<int> d(n, INT_MAX);
        d[src] = 0;
        for (int i = 0; i < K + 1; ++i)
        {
            vector<int> temp(d);
            for (auto e : flights)
            {
                if (d[e[0]] == INT_MAX)
                    continue;
                temp[e[1]] = min(temp[e[1]], d[e[0]] + e[2]);
            }
            d = temp;
        }

        return d[dst] == INT_MAX ? -1 : d[dst];
    }
};
//Dijsktra
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX));
        for (auto e : flights)
        {
            g[e[0]][e[1]] = e[2];
        }
        auto cmp = [](vector<int> left, vector<int> right) {
            return left[0] > right[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push(vector<int>{0, -1, src});
        while (!pq.empty())
        {
            vector<int> cur = pq.top();
            pq.pop();
            int cost = cur[0], k = cur[1], index = cur[2];
            if (index == dst)
                return cost;
            for (int i = 0; i < n; ++i)
            {
                if (g[index][i] == INT_MAX)
                    continue;
                if (k < K)
                {
                    pq.push(vector<int>{cost + g[index][i], k + 1, i});
                }
            }
        }
        return -1;
    }
};
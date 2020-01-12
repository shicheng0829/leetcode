class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]]++;
        }
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto p : mp)
        {
            if (pq.size() < k)
            {
                pq.push(p);
            }
            else
            {
                if (p.second > pq.top().second)
                {
                    pq.pop();
                    pq.push(p);
                }
            }
        }
        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
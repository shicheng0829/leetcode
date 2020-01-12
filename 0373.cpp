class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first + left.second < right.first + right.second; };
        priority_queue<int, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (pq.size() < k)
                {
                    pq.push(make_pair(nums1[i], nums2[j]));
                }
                else if (pq.size() == k)
                {
                    if (nums1[i] + nums2[j] < pq.top().first + pq.top().second)
                    {
                        pq.pop();
                        pq.push(make_pair(nums1[i], nums2[j]));
                    }
                }
            }
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            res.push_back(vector<int>{pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> res;
        multiset<int> height;
        set<pair<int, int>> st;
        vector<int> last = {0, 0};
        height.insert(0);
        for (auto &b : buildings)
        {
            st.insert(make_pair(b[0], -b[2]));
            st.insert(make_pair(b[1], b[2]));
        }
        for (auto &p : st)
        {
            if (p.second < 0)
                height.insert(-p.second);
            else
                height.erase(height.find(p.second));
            int max_h = *height.rbegin();
            if (last[1] != max_h)
            {
                last[0] = p.first;
                last[1] = max_h;
                res.push_back(last);
            }
        }
        return res;
    }
};
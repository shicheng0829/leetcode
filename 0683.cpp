class Solution
{
public:
    int kEmptySlots(vector<int> &bulbs, int K)
    {
        set<int> st;
        for (int i = 0; i < bulbs.size(); ++i)
        {
            auto it = st.insert(bulbs[i]).first;
            auto temp = it;
            temp++;
            if (temp != st.end() && *temp - *it - 1 == K)
            {
                return i + 1;
            }
            temp = it;
            temp--;
            if (temp != st.end() && *it - *temp - 1 == K)
            {
                return i + 1;
            }
        }
        return -1;
    }
};
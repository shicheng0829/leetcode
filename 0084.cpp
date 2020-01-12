class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (st.top() != -1 && heights[i] < heights[st.top()])
            {
                int index = st.top();
                st.pop();
                res = max(res, heights[index] * (i - st.top() - 1));
            }
            st.push(i);
        }
        int n = heights.size();
        while (st.top() != -1)
        {
            int index = st.top();
            st.pop();
            res = max(res, heights[index] * (n - st.top() - 1));
        }
        return res;
    }
};
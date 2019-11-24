class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string &s : tokens)
        {
            if (s == "+")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left + right);
            }
            else if (s == "-")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left - right);
            }
            else if (s == "*")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left * right);
            }
            else if (s == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left / right);
            }
            else
            {
                st.push(atoi(s.c_str()));
            }
        }
        return st.top();
    }
};
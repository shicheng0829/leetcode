class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i)
        {
            char top = st.empty() ? '#' : st.top();
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (top == '(' && s[i] == ')')
                st.pop();
            else if (top == '[' && s[i] == ']')
                st.pop();
            else if (top == '{' && s[i] == '}')
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};
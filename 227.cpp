class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        int temp = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                temp = 10 * temp + (s[i] - '0');
            }
            if ((!isdigit(s[i])) && s[i] != ' ' || i == s.size() - 1)
            {
                if (sign == '+')
                    st.push(temp);
                else if (sign == '-')
                    st.push(-temp);
                else if (sign == '*')
                {
                    int num = st.top() * temp;
                    st.pop();
                    st.push(num);
                }
                else if (sign == '/')
                {
                    int num = st.top() / temp;
                    st.pop();
                    st.push(num);
                }
                temp = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!st.empty())
        {
            res += st.top();
            // cout << st.top() << endl;
            st.pop();
        }
        return res;
    }
};
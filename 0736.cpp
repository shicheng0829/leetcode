class Solution
{
public:
    vector<unordered_map<string, int>> q;
    int evaluate(string expression)
    {
        return helper(expression);
    }

    int helper(string expression)
    {
        // 若为数字， 直接返回
        if (isdigit(expression[0]) || expression[0] == '-')
            return stoi(expression);
        // 复合表达式，解析
        else if (expression[0] == '(')
        {
            if (expression[1] == 'm')
            {
                vector<string> s = parse(expression.substr(6, expression.size() - 7));
                return helper(s[0]) * helper(s[1]);
            }
            else if (expression[1] == 'a')
            {
                vector<string> s = parse(expression.substr(5, expression.size() - 6));
                return helper(s[0]) + helper(s[1]);
            }
            else if (expression[1] == 'l')
            {
                unordered_map<string, int> mp;
                q.push_back(mp);
                vector<string> s = parse(expression.substr(5, expression.size() - 6));
                for (int i = 0; i < s.size() - 1; i += 2)
                {
                    q[q.size() - 1][s[i]] = helper(s[i + 1]);
                }
                int temp = helper(s[s.size() - 1]);
                q.pop_back();
                return temp;
            }
        }
        // 若为字母
        else
        {
            for (int i = q.size() - 1; i >= 0; --i)
            {
                if (q[i].find(expression) != q[i].end())
                    return q[i][expression];
            }
        }
        return -1;
    }

    vector<string> parse(string expression)
    {
        vector<string> strs = split(expression, " ");
        vector<string> res;
        int counter = 0;
        string buf = "";
        for (auto &token : strs)
        {
            for (auto &c : token)
            {
                if (c == '(')
                    counter++;
                else if (c == ')')
                    counter--;
            }
            if (!buf.empty())
                buf += " ";
            buf += token;
            if (counter == 0)
            {
                res.push_back(buf);
                buf = "";
            }
        }
        return res;
    }

    vector<string> split(string expression, string delimiter)
    {
        vector<string> res;
        string token;
        size_t pos;
        while ((pos = expression.find(delimiter)) != string::npos)
        {
            token = expression.substr(0, pos);
            res.push_back(token);
            expression.erase(0, pos + delimiter.size());
        }
        res.push_back(expression);
        return res;
    }
};
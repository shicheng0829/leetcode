class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string maxPrefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            int cur = 0;
            while (cur < strs[i].size() && cur < maxPrefix.size())
            {
                if (strs[i][cur] == maxPrefix[cur])
                    ++cur;
                else
                    break;
            }
            maxPrefix = maxPrefix.substr(0, cur);
        }
        return maxPrefix;
    }
};
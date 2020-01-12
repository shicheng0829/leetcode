class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> cur;
        helper(s, 0, cur, res);
        return res;
    }
    void helper(string &s, int begin, vector<string> &cur, vector<vector<string>> &res)
    {
        if (begin == s.size())
        {
            res.push_back(cur);
            return;
        }
        for (int i = begin; i < s.size(); ++i)
        {
            if (isP(s, begin, i))
            {
                cur.push_back(s.substr(begin, i - begin + 1));
                helper(s, i + 1, cur, res);
                cur.pop_back();
            }
        }
    }
    bool isP(string s, int start, int end)
    {
        int i = start, j = end;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
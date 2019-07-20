class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper("", n, 0, 0, res);
        return res;
    }
    void helper(string cur, int n, int left, int right, vector<string> &res)
    {
        if (left < right)
            return;
        if (left > n || right > n)
            return;
        if (left == n && right == n)
            res.push_back(cur);
        helper(cur + "(", n, left + 1, right, res);
        helper(cur + ")", n, left, right + 1, res);
    }
};
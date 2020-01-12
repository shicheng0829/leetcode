class Solution
{
public:
    unordered_map<int, string> mp;
    vector<string> letterCombinations(string digits)
    {
        mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> res;
        if (digits == "")
            return res;
        helper(digits, 0, "", res);
        return res;
    }
    void helper(string digits, int cur, string now, vector<string> &res)
    {
        if (cur == digits.size())
            res.push_back(now);
        string s = mp[digits[cur] - '0'];
        for (int i = 0; i < s.size(); ++i)
            helper(digits, cur + 1, now + s.substr(i, 1), res);
    }
};
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, -1);
        unordered_set<string> set;
        for (int i = 0; i < wordDict.size(); ++i)
            set.insert(wordDict[i]);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] == 1 && set.find(s.substr(j, i - j)) != set.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()] == 1;
    }
};
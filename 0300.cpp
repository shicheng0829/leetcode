class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0);
        return helper(coins, amount, dp);
    }
    int helper(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (dp[amount] != 0)
            return dp[amount];
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); ++i)
        {
            int temp = helper(coins, amount - coins[i], dp);
            if (temp != -1)
                res = min(temp, res);
        }
        if (res == INT_MAX)
        {
            dp[amount] = -1;
            return -1;
        }
        dp[amount] = res + 1;
        return res + 1;
    }
};
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = INT_MIN, maxP = 1, minP = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                swap(maxP, minP);
            }
            maxP = max(maxP * nums[i], nums[i]);
            minP = min(minP * nums[i], nums[i]);

            res = max(res, maxP);
        }
        return res;
    }
};
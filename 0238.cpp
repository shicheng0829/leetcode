class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        int k = 1;
        for (int i = 1; i < n; ++i)
        {
            k *= nums[i - 1];
            res[i] = k;
        }
        k = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            k *= nums[i + 1];
            res[i] *= k;
        }
        return res;
    }
};
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int res;
        int n = nums.size();
        helper(nums, n - k, 0, n - 1, res);
        return res;
    }
    void helper(vector<int> &nums, int index, int lo, int hi, int &res)
    {
        if (lo > hi)
            return;
        int p = partition(nums, lo, hi);
        if (p == index)
            res = nums[p];
        else if (p > index)
            helper(nums, index, lo, p - 1, res);
        else
            helper(nums, index, p + 1, hi, res);
    }
    int partition(vector<int> &nums, int lo, int hi)
    {
        if (lo == hi)
            return lo;
        int i = lo, j = hi + 1;
        while (1)
        {
            while (nums[++i] < nums[lo] && i != hi)
                ;
            while (nums[--j] > nums[lo] && j != lo)
                ;
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
};
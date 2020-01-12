class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int> &nums, int lo, int hi)
    {
        if (lo == hi)
            return lo;
        int mid = (lo + hi) / 2;
        if (nums[mid] > nums[mid + 1])
            return helper(nums, lo, mid);
        return helper(nums, mid + 1, hi);
    }
};
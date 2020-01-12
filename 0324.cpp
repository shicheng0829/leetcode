class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> input(nums);
        sort(input.rbegin(), input.rend());
        int n = input.size();
        for (int i = 0; i < n / 2; ++i)
        {
            nums[2 * i + 1] = input[i];
        }
        for (int i = n / 2; i < n; ++i)
        {
            nums[2 * (i - n / 2)] = input[i];
        }
    }
};

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
#define a(i) nums[(2 * (i) + 1) % (n | 1)]
        int i = 0, less = 0, more = nums.size() - 1;
        while (i <= more)
        {
            if (a(i) > mid)
                swap(a(i++), a(less++));
            else if (a(i) < mid)
                swap(a(i), a(more--));
            else
                ++i;
        }
    }
};
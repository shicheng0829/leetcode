class Solution
{
public:
    vector<int> index;
    vector<int> temp;
    vector<int> res;
    vector<int> countSmaller(vector<int> &nums)
    {
        if (nums.empty())
            return res;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            index.push_back(i);
        temp = vector<int>(n, 0);
        res = vector<int>(n, 0);
        merge(nums, 0, n - 1);
        return res;
    }
    void merge(vector<int> &nums, int lo, int hi)
    {
        if (lo == hi)
            return;
        int mid = (lo + hi) / 2;
        merge(nums, lo, mid);
        merge(nums, mid + 1, hi);
        for (int i = lo; i <= hi; ++i)
            temp[i] = index[i];
        int i = lo, j = mid + 1, cur = lo;
        while (i <= mid && j <= hi)
        {
            if (nums[temp[i]] <= nums[temp[j]])
            {
                res[temp[i]] += j - mid - 1;
                index[cur++] = temp[i++];
            }
            else
            {
                index[cur++] = temp[j++];
            }
        }
        while (i <= mid)
        {
            res[temp[i]] += hi - mid;
            index[cur++] = temp[i++];
        }
        while (j <= hi)
        {
            index[cur++] = temp[j++];
        }
    }
};
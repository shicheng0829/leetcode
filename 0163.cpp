class Solution
{
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<string> res;
        long long lo = lower, hi = upper;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] - lo == 1)
            {
                res.push_back(to_string(lo));
            }
            else if (nums[i] - lo > 1)
            {
                res.push_back(to_string(lo) + "->" + to_string(nums[i] - 1));
            }
            lo = (long long)nums[i] + 1;
        }
        if (hi - lo == 0)
        {
            res.push_back(to_string(lo));
        }
        else if (hi - lo > 0)
        {
            res.push_back(to_string(lo) + "->" + to_string(hi));
        }
        return res;
    }
};
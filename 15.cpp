class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int lo = i + 1, hi = nums.size() - 1;
            int target = -nums[i];
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == target)
                {
                    res.push_back(vector<int>{nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo + 1] == nums[lo])
                        ++lo;
                    while (lo < hi && nums[hi - 1] == nums[hi])
                        --hi;
                    ++lo;
                    --hi;
                }
                else if (nums[lo] + nums[hi] < target)
                    ++lo;
                else
                    --hi;
            }
        }
        return res;
    }
};
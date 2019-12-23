class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min_num = INT_MAX;
        int big_num = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= min_num)
            {
                min_num = nums[i];
            }
            else if (nums[i] <= big_num)
            {
                big_num = nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
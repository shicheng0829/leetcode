class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int cur = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != cur)
            {
                count--;
                if (count == 0)
                {
                    cur = nums[i];
                    count = 1;
                }
            }
            else
                count++;
        }
        return cur;
    }
};
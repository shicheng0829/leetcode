class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2, -1);
        if (nums.size() == 0)
            return res;
        res[0] = search(nums, target, true);
        if (res[0] == -1)
            return res;
        res[1] = search(nums, target, false);
        return res;
    }
    int search(vector<int> &nums, int target, bool first)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                if (first)
                {
                    if (mid - 1 >= 0 && nums[mid - 1] == nums[mid])
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        return mid;
                    }
                }
                else
                {
                    if (mid + 1 < nums.size() && nums[mid + 1] == nums[mid])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        return mid;
                    }
                }
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, res);
        return res;
    }
    void helper(int first, vector<int> nums, vector<vector<int>>& res)
    {
        if (first == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); i++)
        {
            swap(nums[first], nums[i]);
            helper(first + 1, nums, res);
        }
    }
};
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> cur;
        vector<vector<int>> res;
        helper(cur, 0, res, nums);
        return res;
    }
    void helper(vector<int> &cur, int begin, vector<vector<int>> &res, vector<int> &nums)
    {
        res.push_back(cur);
        for (int i = begin; i < nums.size(); ++i)
        {
            cur.push_back(nums[i]);
            helper(cur, i + 1, res, nums);
            cur.pop_back();
        }
    }
};
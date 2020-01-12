class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i)
        {
            s.insert(nums[i]);
        }
        int max_len = 0;
        for (int cur : s)
        {
            if (s.find(cur - 1) == s.end())
            {
                int len = 0;
                while (s.find(cur) != s.end())
                {
                    ++len;
                    ++cur;
                    max_len = max(len, max_len);
                }
            }
        }
        return max_len;
    }
};
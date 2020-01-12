class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if (s.empty())
            return 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int res = 0;
        while (j < s.size())
        {
            // 向右边扩大窗口
            mp[s[j]]++;
            // 字符串包含不同字符个数大于k，收缩窗口
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                ++i;
            }
            res = max(res, j - i + 1);
            ++j;
        }
        return res;
    }
};
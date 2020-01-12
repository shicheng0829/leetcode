class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int max = 0, i = 0, j = 0, n = s.size();
        for (int j = 0; j < n; ++j)
        {
            if (mp.find(s[j]) != mp.end())
            {
                i = std::max(mp[s[j]], i);
            }
            max = std::max(j - i + 1, max);
            mp[s[j]] = j + 1;
        }
        return max;
    }
};
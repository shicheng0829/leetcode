class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        vector<int> count(26, 0);
        for (int i = 0; i < s.size(); ++i)
            count[s[i] - 'a']++;
        int i = 0;
        while (i < s.size() && count[s[i] - 'a'] >= k)
            ++i;
        if (i == s.size())
            return i;
        int left = longestSubstring(s.substr(0, i), k);
        while (i < s.size() && count[s[i] - 'a'] < k)
            ++i;
        int right = longestSubstring(s.substr(i), k);
        return max(left, right);
    }
};
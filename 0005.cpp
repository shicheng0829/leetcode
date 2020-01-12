class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s == "")
            return "";
        int maxLen = 0;
        int start = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            auto pair1 = spand(s, i, i);
            auto pair2 = spand(s, i, i + 1);
            int len1 = pair1.second - pair1.first + 1;
            if (len1 > maxLen)
            {
                maxLen = len1;
                start = pair1.first;
            }
            int len2 = pair2.second - pair2.first + 1;
            if (len2 > maxLen)
            {
                maxLen = len2;
                start = pair2.first;
            }
        }
        return s.substr(start, maxLen);
    }

private:
    pair<int, int> spand(string s, int i1, int i2)
    {
        int len = 0;
        while (i1 >= 0 && i2 < s.size() && s[i1] == s[i2])
        {
            --i1;
            ++i2;
        }
        return make_pair<int, int>(i1 + 1, i2 - 1);
    }
};
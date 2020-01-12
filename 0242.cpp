class Solution
{
public:
    // sort
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     return s == t;
    // }
    // counter
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> counter(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (counter[i] != 0)
                return false;
        }
        return true;
    }
};
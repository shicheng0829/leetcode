class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.empty())
            return;
        int n = s.size() - 1;
        for (int i = 0; i <= n / 2; ++i)
        {
            swap(s[i], s[n - i]);
        }
    }
};
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !isValid(s[i]))
                ++i;
            while (i < j && !isValid(s[j]))
                --j;
            if (toupper(s[i]) != toupper(s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }
    bool isValid(char c)
    {
        if (c >= '0' && c <= '9')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
};
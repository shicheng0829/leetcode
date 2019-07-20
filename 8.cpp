class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0;
        while (str[i] == ' ')
        {
            ++i;
        }
        int flag = 1;
        if (str[i] == '+')
        {
            flag = 1;
            ++i;
        }
        else if (str[i] == '-')
        {
            flag = -1;
            ++i;
        }
        int res = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
        {
            if (flag == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)))
                return INT_MAX;
            if (flag == -1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' >= 8)))
                return INT_MIN;

            res = res * 10 + (str[i] - '0');
            ++i;
        }
        return res * flag;
    }
};
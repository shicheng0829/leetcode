class Solution
{
public:
    bool isHappy(int n)
    {
        int fast = n;
        int slow = n;
        while (1)
        {
            fast = happy(fast);
            fast = happy(fast);
            slow = happy(slow);
            if (slow == 1)
                return true;
            if (fast == slow)
                return false;
        }
    }
    int happy(int n)
    {
        int res = 0;
        while (n)
        {
            int digit = n % 10;
            res += digit * digit;
            n /= 10;
        }
        return res;
    }
};
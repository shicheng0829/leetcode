class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        long long lo = 0;
        long long hi = 2 * (long long)x;
        while (lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if ((mid + 1) * (mid + 1) > x && mid * mid <= x)
                return mid;
            else if (mid * mid < x)
            {
                lo = mid + 1;
            }
            else if (mid * mid > x)
            {
                hi = mid - 1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0)
        {
            x = 1.0 / x;
            N = -N;
        }
        return helper(x, N);
            
    }
    double helper(double x, long long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double temp = helper(x, n / 2);
        if (n % 2 == 1)
            return temp * temp * x;
        else
            return temp * temp;
    }
};
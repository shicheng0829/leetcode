class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> vec(n, -1);
        for (int i = 2; i < n; ++i)
        {
            for (long j = i; j * i < n; ++j)
            {
                vec[j * i] = 1;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (vec[i] == -1)
                ++count;
        }
        return count;
    }
};
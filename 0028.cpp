class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        const int R = 256;
        const int M = haystack.size();
        const int N = needle.size();
        if (N == 0)
            return 0;
        vector<vector<int>> dfa(R, vector<int>(N, 0));
        dfa[needle[0]][0] = 1;
        for (int X = 0, j = 1; j < N; j++)
        {
            for (int c = 0; c < R; c++)
            {
                dfa[c][j] = dfa[c][X];
            }
            dfa[needle[j]][j] = j + 1;
            X = dfa[needle[j]][X];
        }
        int i, j;
        for (i = 0, j = 0; i < M && j < N; i++)
            j = dfa[haystack[i]][j];
        if (j == N)
            return i - N;
        else
            return -1;
    }
};
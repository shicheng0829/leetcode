class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        string cur = "";
        int A_size = A.size(), B_size = B.size();
        // consider A = "ab", B = "b|abab|a", 
        int max_len = A_size * 2 + B_size;
        for (int cnt = 0; cur.size() < max_len; cur += A, cnt++)
        {
            if (cur.find(B) != string::npos)
                return cnt;
        }
        return -1;
    }
};
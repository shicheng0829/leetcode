class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";
        vector<int> tVec(256, 0), sVec(256, 0);
        int M = t.size();
        for (int i = 0; i < M; ++i)
        {
            tVec[t[i]]++;
        }
        int L = 0, R = 0, N = s.size();
        int count = 0;
        vector<int> res = {-1, 0, 0};
        while (R < N)
        {
            if (sVec[s[R]] < tVec[s[R]])
            {
                count++;
            }
            sVec[s[R]]++;
            while (L <= R && count == M)
            {
                if (res[0] == -1 || R - L + 1 < res[0])
                {
                    res[0] = R - L + 1;
                    res[1] = L;
                    res[2] = R;
                }
                sVec[s[L]]--;
                if (sVec[s[L]] < tVec[s[L]])
                {
                    count--;
                }
                L++;
            }
            R++;
        }
        return res[0] == -1 ? "" : s.substr(res[1], res[0]);
    }
};
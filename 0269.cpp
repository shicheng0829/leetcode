class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        vector<vector<int>> G(26, vector<int>(26, 0));
        vector<int> inDegree(26, -1);
        for (int i = 1; i < words.size(); ++i)
        {
            for (int j = 0; j < min(words[i].size(), words[i - 1].size()); ++j)
            {
                if (words[i - 1][j] - 'a' != words[i][j] - 'a')
                {
                    G[words[i - 1][j] - 'a'][words[i][j] - 'a'] = 1;
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                if (inDegree[words[i][j] - 'a'] == -1)
                {
                    inDegree[words[i][j] - 'a'] = 0;
                    count++;
                }
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (G[i][j] == 1)
                {
                    inDegree[j]++;
                }
            }
        }
        string res;
        queue<int> q;
        for (int i = 0; i < 26; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int cur = q.front();
            res += 'a' + cur;
            count--;
            q.pop();
            for (int i = 0; i < 26; ++i)
            {
                if (G[cur][i] == 1)
                {
                    inDegree[i]--;
                    G[cur][i] = 0;
                    if (inDegree[i] == 0)
                        q.push(i);
                }
            }
        }
        return count == 0 ? res : "";
    }
};
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites)
        {
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> res;
        while (!q.empty())
        {
            int cur = q.front();
            res.push_back(cur);
            q.pop();
            numCourses--;
            for (auto &p : prerequisites)
            {
                if (p[1] == cur)
                {
                    indegree[p[0]]--;
                    if (indegree[p[0]] == 0)
                        q.push(p[0]);
                }
            }
        }
        if (numCourses != 0)
        {
            return vector<int>{};
        }
        else
        {
            return res;
        }
    }
};
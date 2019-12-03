class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ingress(numCourses, 0);
        for (auto &vec : prerequisites)
        {
            ingress[vec[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (ingress[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int first = q.front();
            q.pop();
            numCourses--;
            for (auto &vec : prerequisites)
            {
                if (vec[1] == first)
                {
                    ingress[vec[0]]--;
                    if (ingress[vec[0]] == 0)
                        q.push(vec[0]);
                }
                else
                    continue;
            }
        }
        return numCourses == 0;
    }
};
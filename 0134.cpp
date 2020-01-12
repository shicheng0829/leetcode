class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int cur = 0, total = 0, res = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0)
            {
                cur = 0;
                res = i + 1;
            }
        }
        return total < 0 ? -1 : res;
    }
};
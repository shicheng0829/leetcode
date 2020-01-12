class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<int> start(n, 0);
        vector<int> end(n, 0);
        for (int i = 0; i < n; ++i)
        {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int start_ptr = 0, end_ptr = 0;
        int res = 0;
        int cur = 0;
        while (start_ptr < n)
        {
            if (start[start_ptr] < end[end_ptr])
            {
                start_ptr++;
                cur++;
                res = max(cur, res);
            }
            else
            {
                end_ptr++;
                cur--;
            }
        }
        return res;
    }
};
class Solution
{
public:
    string nextClosestTime(string time)
    {
        vector<int> vec;
        string res;
        int diff = INT_MAX;
        for (int i = 0; i < 5; ++i)
        {
            if (i == 2)
                continue;
            vec.push_back(time[i] - '0');
        }
        int target_time = ((time[0] - '0') * 10 + time[1] - '0') * 60 + (time[3] - '0') * 10 + time[4] - '0';
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                int hours = vec[i] * 10 + vec[j];
                if (hours >= 24)
                    continue;
                for (int k = 0; k < 4; ++k)
                {
                    for (int l = 0; l < 4; ++l)
                    {
                        int minutes = vec[k] * 10 + vec[l];
                        if (minutes >= 60)
                            continue;
                        int cur = hours * 60 + minutes;
                        int cur_diff = cur - target_time;
                        if (cur_diff <= 0)
                            cur_diff += 24 * 60;
                        if (cur_diff < diff)
                        {
                            res = to_string(vec[i]) + to_string(vec[j]) + ":" + to_string(vec[k]) + to_string(vec[l]);
                            diff = cur_diff;
                        }
                    }
                }
            }
        }
        return res;
    }
};
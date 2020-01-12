class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int maxS = 0;
        while (l <= r)
        {
            int nowS = (r - l) * min(height[l], height[r]);
            maxS = nowS > maxS ? nowS : maxS;
            if (height[l] > height[r])
                --r;
            else
                ++l;
        }
        return maxS;
    }
};
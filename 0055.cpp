class Solution {
public:
    bool canJump(vector<int>& nums) {
        int further = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (further < i)
                return false;
            further = max(further, i + nums[i]);
        }
        return true;
    }
};
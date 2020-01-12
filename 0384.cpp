class Solution
{
public:
    vector<int> origin;
    vector<int> vec;
    Solution(vector<int> &nums)
    {
        vec = nums;
        origin = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        vec = origin;
        return vec;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            swap(vec[i], vec[rangeRandom(i, vec.size())]);
        }
        return vec;
    }

    int rangeRandom(int min, int max)
    {
        srand(clock());
        return rand() % (max - min) + min;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
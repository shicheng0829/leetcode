class Vector2D
{
public:
    int i = 0;
    int n = 0;
    vector<int> vec;
    Vector2D(vector<vector<int>> &v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                vec.push_back(v[i][j]);
                ++n;
            }
        }
    }

    int next()
    {
        return vec[i++];
    }

    bool hasNext()
    {
        return i < n;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
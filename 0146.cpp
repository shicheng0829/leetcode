class LRUCache
{
public:
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        auto it = mp[key];
        int value = (*it).second;
        l.erase(it);
        l.push_front(pair<int, int>{key, value});
        mp[key] = l.begin();
        return value;
    }

    void put(int key, int value)
    {
        // find the key
        if (mp.find(key) != mp.end())
        {
            // update key
            l.erase(mp[key]);
            l.push_front(pair<int, int>{key, value});
            mp[key] = l.begin();
        }
        else
        {
            // delete back node and push front node
            if (l.size() == n)
            {
                mp.erase(l.back().first);
                l.pop_back();
            }
            l.push_front(pair<int, int>{key, value});
            mp[key] = l.begin();
        }
    }

private:
    int n;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
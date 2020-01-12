// 暴力回溯
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st;
        for (auto str : wordDict)
            st.insert(str);
        vector<string> res;
        helper(s, st, 0, "", res);
        return res;
    }
    void helper(string &s, unordered_set<string> &st, int cur, string path, vector<string> &res)
    {
        if (cur == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = cur; i < s.size(); ++i)
        {
            string temp = s.substr(cur, i - cur + 1);
            if (st.find(temp) != st.end())
            {
                if (path == "")
                    helper(s, st, i + 1, path + temp, res);
                else
                    helper(s, st, i + 1, path + " " + temp, res);
            }
        }
    }
};
// 记忆式回溯
class Solution
{
public:
    unordered_map<int, vector<string>> mp;
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st;
        for (auto str : wordDict)
            st.insert(str);
        vector<string> res = helper(s, st, 0);
        return res;
    }
    vector<string> helper(string &s, unordered_set<string> &st, int cur)
    {
        if (mp.find(cur) != mp.end())
            return mp[cur];
        vector<string> res;
        if (cur == s.size())
        {
            res.push_back("");
        }
        for (int end = cur; end < s.size(); ++end)
        {
            string temp = s.substr(cur, end - cur + 1);
            if (st.find(temp) != st.end())
            {
                vector<string> backs = helper(s, st, end + 1);

                for (auto str : backs)
                {
                    res.push_back(str == "" ? temp + str : temp + " " + str);
                }
            }
        }
        mp[cur] = res;
        return res;
    }
};
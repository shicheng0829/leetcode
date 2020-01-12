class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<string>> mp;
        for (auto word : wordList)
        {
            for (int i = 0; i < word.size(); ++i)
            {
                string newword = word.substr(0, i) + '*' + word.substr(i + 1);
                mp[newword].push_back(word);
            }
        }
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        unordered_set<string> s;
        while (!q.empty())
        {
            pair<string, int> p = q.front();
            q.pop();
            string cur_word = p.first;
            int layer = p.second;
            for (int i = 0; i < cur_word.size(); ++i)
            {
                string newword = cur_word.substr(0, i) + '*' + cur_word.substr(i + 1);
                for (auto &word : mp[newword])
                {
                    if (s.find(word) == s.end())
                    {
                        if (word == endWord)
                            return layer + 1;
                        q.push(make_pair(word, layer + 1));
                        s.insert(word);
                    }
                }
            }
        }
        return 0;
    }
};
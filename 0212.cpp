class Solution
{
public:
    class Tries
    {
    public:
        Tries()
        {
            isWord = false;
        }
        unordered_map<char, Tries *> next;
        bool isWord;
    };
    void insert(Tries *root, string &word)
    {
        for (auto &c : word)
        {
            if (root->next.find(c) == root->next.end())
            {
                root->next[c] = new Tries();
            }
            root = root->next[c];
        }
        root->isWord = true;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        unordered_set<string> st;
        if (board.empty())
            return res;
        Tries *t = new Tries();
        for (auto &word : words)
        {
            insert(t, word);
        }
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                helper(board, visit, i, j, "", t, st);
            }
        }
        for (auto &str : st)
            res.push_back(str);
        return res;
    }
    vector<vector<int>> shift = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void helper(vector<vector<char>> &board, vector<vector<bool>> &visit, int i, int j, string cur, Tries *root, unordered_set<string> &st)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (visit[i][j])
            return;
        if (root->next.find(board[i][j]) == root->next.end())
            return;
        visit[i][j] = true;
        root = root->next[board[i][j]];
        cur = cur + board[i][j];
        if (root->isWord)
        {
            st.insert(cur);
        }
        for (auto &s : shift)
        {
            helper(board, visit, i + s[0], j + s[1], cur, root, st);
        }
        visit[i][j] = false;
    }
};
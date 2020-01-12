class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *root = this;
        for (int i = 0; i < word.size(); ++i)
        {
            if (root->next[word[i] - 'a'] == nullptr)
            {
                root->next[word[i] - 'a'] = new Trie();
            }
            root = root->next[word[i] - 'a'];
        }
        root->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *root = this;
        for (int i = 0; i < word.size(); ++i)
        {
            if (root->next[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            root = root->next[word[i] - 'a'];
        }
        return root->isEnd == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *root = this;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (root->next[prefix[i] - 'a'] == nullptr)
            {
                return false;
            }
            root = root->next[prefix[i] - 'a'];
        }
        return true;
    }
    Trie *next[26] = {};
    bool isEnd = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
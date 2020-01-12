/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        helper(root, s);
        return s;
    }
    void helper(TreeNode *root, string &res)
    {
        if (root == nullptr)
        {
            res += "null ";
            return;
        }
        res += to_string(root->val) + " ";
        helper(root->left, res);
        helper(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream iss(data);
        vector<string> results((istream_iterator<std::string>(iss)),
                               istream_iterator<std::string>());
        int cur = 0;
        return helper2(results, cur);
    }
    TreeNode *helper2(vector<string> &vec, int &cur)
    {
        if (vec[cur] == "null")
        {
            cur++;
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(vec[cur]));
        cur++;
        root->left = helper2(vec, cur);
        root->right = helper2(vec, cur);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
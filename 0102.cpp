/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> layer;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *cur = q.front();
                layer.push_back(cur->val);
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(layer);
        }
        return res;
    }
};
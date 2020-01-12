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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        q.push(root);
        bool flag = true;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> layer(n, 0);
            for (int i = 0; i < n; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (flag)
                {
                    layer[i] = cur->val;
                }
                else
                {
                    layer[n - 1 - i] = cur->val;
                }
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            flag = !flag;
            res.push_back(layer);
        }
        return res;
    }
};
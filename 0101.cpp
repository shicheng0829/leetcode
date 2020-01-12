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
    // recursive
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    bool isMirror(TreeNode* r1, TreeNode* r2)
    {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        if (r1 == nullptr || r2 == nullptr)
            return false;
        return (r1->val == r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }
    // non-recursive
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while (!q.empty())
        {
            TreeNode *r1 = q.front();
            q.pop();
            TreeNode *r2 = q.front();
            q.pop();
            if (r1 == nullptr && r2 == nullptr)
                continue;
            if (r1 == nullptr || r2 == nullptr)
                return false;
            if (r1->val != r2->val)
                return false;
            q.push(r1->left);
            q.push(r2->right);
            q.push(r1->right);
            q.push(r2->left);
        }
        return true;
    }
};
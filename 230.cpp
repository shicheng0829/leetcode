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
    int kthSmallest(TreeNode *root, int k)
    {
        int res;
        int cur = 0;
        helper(root, cur, k, res);
        return res;
    }
    void helper(TreeNode *root, int &cur, int k, int &res)
    {
        if (root == nullptr)
            return;
        helper(root->left, cur, k, res);
        ++cur;
        if (cur == k)
            res = root->val;
        helper(root->right, cur, k, res);
    }
};
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
    int maxDepth(TreeNode *root)
    {
        int maxLen = 0;
        helper(root, 1, maxLen);
        return maxLen;
    }
    void helper(TreeNode *root, int level, int &maxLen)
    {
        if (root == nullptr)
            return;
        maxLen = max(level, maxLen);
        helper(root->left, level + 1, maxLen);
        helper(root->right, level + 1, maxLen);
    }
};
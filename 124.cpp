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
    int maxPathSum(TreeNode *root)
    {
        int maxPathSum = INT_MIN;
        helper(root, maxPathSum);
        return maxPathSum;
    }
    int helper(TreeNode *root, int &maxPathSum)
    {
        if (root == nullptr)
            return 0;
        int left = max(helper(root->left, maxPathSum), 0);
        int right = max(helper(root->right, maxPathSum), 0);
        int cur = root->val + left + right;
        maxPathSum = max(maxPathSum, cur);
        return root->val + max(left, right);
    }
};
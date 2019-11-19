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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2)
    {
        if (s1 > e1 || s2 > e2)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[s1]);
        int mid = -1;
        for (int i = s2; i <= e2; ++i)
        {
            if (inorder[i] == preorder[s1])
                mid = i;
        }
        int left = mid - s2;
        root->left = helper(preorder, inorder, s1 + 1, s1 + left, s2, mid - 1);
        root->right = helper(preorder, inorder, s1 + left + 1, e1, mid + 1, e2);
        return root;
    }
};
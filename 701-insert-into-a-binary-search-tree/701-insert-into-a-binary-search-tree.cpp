/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void solve(TreeNode *root, int val)
        {
            if (root == NULL) return;
            if (val > root->val)
            {
                if (root->right == NULL)
                {
                    root->right = new TreeNode(val);
                    return;
                }
                else
                {
                    solve(root->right, val);
                }
            }
            else
            {
                if (root->left == NULL)
                {
                    root->left = new TreeNode(val);
                    return;
                }
                else
                {
                    solve(root->left, val);
                }
            }
        }
    TreeNode* insertIntoBST(TreeNode *root, int val)
    {
        if(root==NULL)return new TreeNode(val);
        solve(root, val);
        return root;
    }
};
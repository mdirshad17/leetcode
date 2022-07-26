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
        long long prev = LONG_MIN;
    int solve(TreeNode *root)
    {
        if (!root)
        {
            return 1;
        }
        int lp = solve(root->left);
        if (lp == 0) return 0;
        if (prev >=root->val)
        {
            return 0;
        }
        prev = root->val;

        int rp = solve(root->right);
        if (rp == 0) return 0;
        return 1;
    }
    bool isValidBST(TreeNode *root)
    {
        return solve(root);
    }
};
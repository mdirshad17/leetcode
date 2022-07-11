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
        int maxlevel = 1;
    vector<int> res;
    void solve(TreeNode *root, int level)
    {
        if (!root) return;
        if (level== maxlevel)
        {
            res.push_back(root->val);
            maxlevel++;
        }
        solve(root->right, level + 1);
        solve(root->left, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        solve(root, 1);
        return res;
    }
};
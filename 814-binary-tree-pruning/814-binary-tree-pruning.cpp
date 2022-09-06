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
#define Node TreeNode
    TreeNode* pruneTree(TreeNode *root)
    {
        if (!root) return NULL;
        Node *left = pruneTree(root->left);
        Node *right = pruneTree(root->right);
        if (left == NULL)
        {
            root->left = NULL;
        }
        if (right == NULL)
        {
            root->right = NULL;
        }
        if (left || right || root->val == 1)
        {
            return root;
        }
        return NULL;
    }
};
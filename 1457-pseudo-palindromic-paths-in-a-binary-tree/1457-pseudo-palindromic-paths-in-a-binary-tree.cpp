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
        int solve(TreeNode *root, int *a)
        {
            if(!root)return 0;
            if (!root->left && !root->right)
            {
                int cnt = 0;
                 a[root->val] ^= 1;
                for (int i = 0; i < 10; i++)
                {
                    cnt += (a[i] == 1);
                }
                 a[root->val] ^= 1;
                return (cnt <= 1);
            }
            a[root->val] ^= 1;
            int ans = solve(root->left, a);
            ans += solve(root->right, a);
            a[root->val] ^= 1;
            return ans;
        }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int a[10] = { 0 };
        return solve(root, a);
    }
};
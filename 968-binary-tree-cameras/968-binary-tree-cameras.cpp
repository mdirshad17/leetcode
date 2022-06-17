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
        map<pair<TreeNode*,int>,int> mp[2];
        int solve(TreeNode *root, int p, int c)
        {
            if (!root) return 0;
            if(mp[c].count({root,p}))return mp[c][{root,p}];
           	// placing at current node
            int op1 = 1 + solve(root->right, 1, 0) + solve(root->left, 1, 0);

           	// through parent
            int op2 = INT_MAX / 10;

            if (p == 1)
            {
                op2 = solve(root->left, 0, 0) + solve(root->right, 0, 0);
            }

            int op3 = INT_MAX / 10;

            if (c == 1)
            {
                op2 = INT_MAX / 10;
            }

            if (c == 0)
            {
               	// through child
                if (root->right)
                {
                    op3 = min(op3, solve(root->right, 0, 1) + solve(root->left, 0, 0));
                }
                if (root->left)
                {
                    op3 = min(op3, solve(root->right, 0, 0) + solve(root->left, 0, 1));
                }
            }
            return mp[c][{root,p}]=min({op1,op2,op3});
        }
    int minCameraCover(TreeNode *root)
    {
        return solve(root, 0, 0);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode * root,int sum){
        if(!root)return 0;
        if(root->left==NULL && root->right==NULL){
            if(sum==root->val)return 1;
            return 0;
        }
        int op1=solve(root->left,sum-root->val);
        int op2=solve(root->right,sum-root->val);
        return (op1|op2);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int f=solve(root,targetSum);
        return f;
    }
};
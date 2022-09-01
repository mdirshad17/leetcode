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
    int solve(TreeNode * root,int val){
        if(!root)return 0;
        return solve(root->left,max(val,root->val))+solve(root->right,max(val,root->val))+(root->val>=val);
        
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
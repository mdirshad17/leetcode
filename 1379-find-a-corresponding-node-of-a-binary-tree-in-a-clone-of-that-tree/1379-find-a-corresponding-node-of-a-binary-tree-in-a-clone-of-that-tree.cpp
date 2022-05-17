/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode * solve(TreeNode * root,TreeNode * target){
        if(!root)return NULL;
        if(root->val==target->val)return root;
        TreeNode * lp=solve(root->left,target);
        TreeNode * rp=solve(root->right,target);
        if(lp)return lp;
        if(rp)return rp;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(cloned,target);
    }
};
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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root)return NULL;
       int l=p->val;
       int r=q->val;
        if(l>r)swap(l,r);
        if(root->val>=l && root->val<=r){
            return root;
        }
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        TreeNode * right=lowestCommonAncestor(root->right,p,q);
        if(left)return left;
        if(right)return right;
        return NULL;
    }
};
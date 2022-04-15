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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)return root;
        TreeNode * lp=trimBST(root->left, low, high);
        TreeNode * rp=trimBST(root->right, low, high);
        if((root->val)<low||root->val>high){
            // cout<<root->val<<endl;
            if(!rp){
                // cout<<
                return lp;
            }
            TreeNode * gp=rp;
            while(gp->left){
                gp=gp->left;
            }
            gp->left=lp;
            return rp;
        }
        TreeNode * res=new TreeNode(root->val);
        res->left=lp;
        res->right=rp;
        return res;
        
    }
};
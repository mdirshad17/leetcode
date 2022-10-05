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
    TreeNode * solve(TreeNode * root,int dp,int val,int dpr,TreeNode * parent){
        if(dp==dpr){
            
            if(parent==NULL){
                TreeNode * nr=new TreeNode(val);
                nr->left=root;
                return nr;
            }
            TreeNode * nr=new TreeNode(val);
            if(parent->left==root){
                nr->left=root;
            }else nr->right=root;
            
            return nr;
        }
        
        if(!root)return root;
        root->left=solve(root->left,dp+1,val,dpr,root);
        root->right=solve(root->right,dp+1,val,dpr,root);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)return root;
        return solve(root,1,val,depth,NULL);
    }
};
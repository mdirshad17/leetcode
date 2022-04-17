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
    TreeNode * ans=NULL;
    TreeNode * p;
    void solve(TreeNode * root){
        if(!root){
            return;
        }
        solve(root->left);
        if(!ans){
            ans=new TreeNode(root->val);
            p=ans;
        }else {
            p->right=new TreeNode(root->val);
            p->left=NULL;
            p=p->right;
            
        }
        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
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
    string res;
    void solve(TreeNode * root){
        if(!root)return;
        res+=to_string(root->val);
        if(!root->left && !root->right) return;
        if(root->left){
            res+='(';
            solve(root->left);
            res+=')';
        }else{
            res+="()";
        }
        if(root->right){
             res+='(';
            solve(root->right);
            res+=')';
        }
        
    }
    string tree2str(TreeNode* root) {
        // return "";
        solve(root);
        return res;
    }
};
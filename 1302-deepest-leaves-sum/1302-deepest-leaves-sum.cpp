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
    int ml=0;
    int ans=0;
    int sum=0;
    void solve(TreeNode * root,int lev){
        if(!root)return;
        if(ml==lev){
            sum+=root->val;
            
        }else if(ml<lev){
            ml=lev;
            sum=root->val;
        }
        solve(root->left,lev+1);
        solve(root->right,lev+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        solve(root,1);
        return sum;
    }
};
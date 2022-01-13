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
    int gans=0;
    map<pair<TreeNode*,int>,int>  mp;
    int solve(TreeNode * root,int dir){
        if(!root)return 0;
        // start new from here
        if(mp.count({root,dir})) return mp[{root,dir}];
        int op1=1+max(solve(root->left,-1),solve(root->right,1));
        gans=max(gans,op1);
        // move according to the parent
        if(dir==1){
            return mp[{root,dir}]=1+solve(root->left,-1);
        }else return mp[{root,dir}]=1+solve(root->right,1);
        
        
    }
    int longestZigZag(TreeNode* root) {
        solve(root,0); 
        return gans-1;
    }
};
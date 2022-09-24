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
    vector<vector<int>> RES;
    vector<int> V;
    void solve(TreeNode * root,int val){
        if(!root)return;
        if(!root->left  && !root->right){
            if(val==root->val){
                V.push_back(root->val);
                RES.push_back(V);
                V.pop_back();
            }
            return;
        }
        V.push_back(root->val);
        solve(root->left,val-root->val);
        solve(root->right,val-root->val);
        V.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return RES;
    }
};
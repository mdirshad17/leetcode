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
    #define Node TreeNode
    int runC(Node * root,int k){
        if(!root)return 0;
        if(root->val==k)return 1;
        if(root->val<k)return runC(root->right,k);
        return runC(root->left,k);
    }
    int solve(Node * root,int val,Node * P){
        if(!root)return 0;
        int Sv=val-root->val;
        int l=0;
        if(Sv!=root->val)l=runC(P,Sv);
        if(l)return 1;
        return (solve(root->left,val,P)||solve(root->right,val,P));
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root)return 0;
        return solve(root,k,root);
    }
};
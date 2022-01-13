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
    bool isEvenOddTree(TreeNode* root) {
       if(!root) return 1;
        queue<TreeNode*>q;
            q.push(root);
        int l=0;
        while(q.size()){
            int  ns=q.size();
            int pr=INT_MIN;
            if(l==1) pr=INT_MAX;
            while(ns--){
                TreeNode * d=q.front();
                q.pop();
                int val=d->val;
                if(l){
                    // cout<<val<<" "<<pr<<endl;
                    if((val&1)||val>=pr) return 0;
                    pr=val;
                }else{
                    if((val&1)==0||val<=pr) return 0;
                    pr=val;
                }
                if(d->left) q.push(d->left);
                if(d->right) q.push(d->right);
                
                
            }l=(l+1)%2;
        }
        return 1;
    }
};
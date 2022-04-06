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
    #define ll long long 
    #define M 1000000007
    ll maxans=0;
    ll sum=0;
    void getsum(TreeNode * root){
        if(!root)return;
        sum+=root->val;
        getsum(root->left);
        getsum(root->right);
    }
    int solve(TreeNode * root){
        if(!root)return 0;
        ll lp=solve(root->left);
        ll rp=solve(root->right);
        ll extra=(sum-(lp+rp+root->val));
        // split from left
        ll rem_left=extra+rp+root->val;
        ll prod=(lp*rem_left);
        maxans=max(maxans,prod);
        // split from right
        ll rem_right=extra+lp+root->val;
        prod=rp*rem_right;
        maxans=max(maxans,prod);
        return lp+rp+root->val;
    }
    int maxProduct(TreeNode* root) {
        getsum(root);
        solve(root);
        maxans=maxans%M;
        return maxans;
    }
};
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
    int solve(Node * root,long long leftrange,long long rightrange){
        if(root==NULL)return true;
        // if(leftrange<=root->val && rightrange>=root->val)
        if(leftrange>root->val||rightrange<root->val)return 0;
        
        int lp=solve(root->left,leftrange,1LL*root->val-1);
        int rp=solve(root->right,1LL*root->val+1,rightrange);
        if(lp && rp)return 1;
        return 0;
    }
    bool isValidBST(TreeNode* root) {
        long long leftrange=LONG_MIN;
        long long rightrange=LONG_MAX;
        int f=solve(root,leftrange,rightrange);
        return f;
    }
};
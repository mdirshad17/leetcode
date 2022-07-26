/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #define Node TreeNode
    Node * ans=NULL;
    int getLCA(Node * root,Node * p,Node * q){
        if(!root)return 0;
        int lp=getLCA(root->left,p,q);
        int rp=getLCA(root->right,p,q);
        if(lp && rp){
            ans=root;
            return 1;
        }
        if(lp|rp){
            if(root==p||root==q){
                ans=root;
            }
            return 1;
        }
        if(root==p||root==q)return 1;
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getLCA(root,p,q);
        return ans;
    }
};
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
    void flatten(TreeNode* root) {
        if(!root)return;
        if(!root->left && !root->right)return;
        flatten(root->left);
        flatten(root->right);
        Node * ori=root->right;
        root->right=root->left;
        root->left=NULL;
        Node * rip=root;;
        while(rip->right){
            // cout<<rip->val<<" ";
            rip=rip->right;
        }
        // cout<<endl;
        // cout<<rip->val<<endl;
        rip->right=ori;
        return;
    }
};
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
    // HCL stands for height calculator
    #define Node TreeNode
    int HCL(Node * root){
        if(!root)return 0;
        int HTRL=HCL(root->left);
        int HTRR=HCL(root->right);
        int HTR=1+max(HTRL,HTRR);
        // cout<<root->val<<" "<<HTR<<"\n";
        return HTR;
        
    } 
    int maxDepth(TreeNode* root) {
        
        return HCL(root);
    }
};
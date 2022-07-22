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
    void PO(Node * node,int &maxlevel,int nodelevel,vector<int> & res){
    if(node==NULL)return;
    if(maxlevel<nodelevel){
        res.push_back(node->val);
        maxlevel++;
    }
    // swap(node->left,node->right);
    PO(node->right,maxlevel,nodelevel+1,res);    
    PO(node->left,maxlevel,nodelevel+1,res);
   
    
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)return res;
        int maxlevel=0;
        int nodelevel=1;
        PO(root,maxlevel,nodelevel,res);
        return res;
    }
};
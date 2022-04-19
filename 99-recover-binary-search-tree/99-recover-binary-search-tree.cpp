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
    TreeNode * prev=NULL;
    int f1=0;
    int ff=-1;
    int ss=-1;
    void solve(TreeNode * root)
    {
        if(!root)
            return;
        solve(root->left);
        if(prev && prev->val>=root->val)
        {
            if(f1==0)
            {
                ff=prev->val;
                f1=1;
            }
            ss=root->val;
        }prev=root;
        solve(root->right);
    }
    void getdone(TreeNode * root)
    {
        if(!root){
            return;
        }
        if(root->val==ff)
        {
            root->val=ss;
        }else if(root->val==ss)
        {
            root->val=ff;
        }
        getdone(root->left);
        getdone(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        solve(root);
        getdone(root);
      return;    
    }
};
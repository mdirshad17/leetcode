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
    int Node=0;
    unordered_map<int,int> mp;
    TreeNode * solve(int l,int r,vector<int> & inorder,vector<int> & preorder){
        if(l>r)return NULL;
        
        int val=preorder[Node];
        Node++;
        // cout<<l<<" "<<r<<endl;
        // if(l==r)return new TreeNode(val);
        TreeNode * root=new TreeNode(val);
        root->left=solve(l,mp[val]-1,inorder,preorder);
        root->right=solve(mp[val]+1,r,inorder,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(0,n-1,inorder,preorder);
    }
};
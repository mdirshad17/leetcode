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
    Node* solve(int l,int r,vector<int> & nums){
        if(l>r)return NULL;
        if(l==r)return new Node(nums[l]);
        int mid=(l+r)>>1;
        Node * root=new Node(nums[mid]);
        root->left=solve(l,mid-1,nums);
        root->right=solve(mid+1,r,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);
    }
};
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
    #define maxn 300005
    int a[maxn];
    int offset;
    void get(TreeNode * root)
    {
        if(root==NULL)
        {
            return;
        }
        int f=offset+root->val;
        a[f]++;
        get(root->left);
        get(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        offset=100003;
        vector<int> res;
        get(root1);
        get(root2);
        for(int i=0;i<maxn;i++)
        {
            while((a[i])--)
            {
                res.push_back(i-offset);
            }
        }
        return res;
    }
};
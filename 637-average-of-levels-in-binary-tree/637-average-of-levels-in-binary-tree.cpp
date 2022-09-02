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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int ns=q.size();
            int sz=ns;
            ll sum=0;
            while(ns--){
                TreeNode * top=q.front();
                sum+=(1LL*top->val);
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            double lvlavg=(sum*1.0)/sz;
            res.push_back(lvlavg);
        }
        return res;
            
    }
};
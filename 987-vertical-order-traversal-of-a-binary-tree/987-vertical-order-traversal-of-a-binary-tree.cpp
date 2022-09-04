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
    #define pii pair<int,int>
    #define Node TreeNode
    map<int,vector<pii>> mp;
    
    void solve(Node * root,int y,int x){
        if(!root)return;
        mp[y].push_back({root->val,x});
        solve(root->left,y-1,x+1);
        solve(root->right,y+1,x+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int> > res;
        for(auto & x:mp){
            sort(x.second.begin(),x.second.end(),[](pii & a,pii & b){
                if(a.second==b.second) return a.first<b.first;
                return a.second<b.second;
            });
           vector<int> v;
            for(int i=0;i<x.second.size();i++){
                v.push_back(x.second[i].first);
            }
            res.push_back(v);
        }
        return res;
    }
};
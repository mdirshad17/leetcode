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
    
    void PRT(Node * node,int x,int y,map<int,vector<pair<int,int>>> & mp){
        if(node==NULL)return;
        mp[x].push_back({node->val,y});
        PRT(node->left,x-1,y+1,mp);
        PRT(node->right,x+1,y+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        map<int,vector<pair<int,int>> > mp;
        int x=0, y=0;
        PRT(root,x,y,mp);
        for(auto x:mp){
            sort(x.second.begin(),x.second.end(),[](pair<int,int> & a,pair<int,int> & b){
                if(a.second==b.second)return a.first<b.first;
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
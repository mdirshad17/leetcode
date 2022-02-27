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
    #define ll long long 
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)return 0;
        queue<pair<Node*,ll> > q;
        q.push({root,0});
        ll ans=0;
        ll prlm=0;
        while(q.size()){
            ll ns=q.size();
            ll minel=LONG_MAX;
            ll maxel=LONG_MIN;
            while(ns--){
                pair<Node*,ll> d=q.front();
                q.pop();
                root=d.first;
                minel=min(minel,d.second);
                maxel=max(maxel,d.second);
                if(root->left){
                    q.push({root->left,2LL*d.second-1-prlm});
                }
                if(root->right){
                    q.push({root->right,2LL*d.second+1-prlm});
                }
            }
            ans=max(ans,(maxel-minel)/2+1);
            prlm=minel;
        }
        // cout<<ans<<endl;
        return ans;
    }
};
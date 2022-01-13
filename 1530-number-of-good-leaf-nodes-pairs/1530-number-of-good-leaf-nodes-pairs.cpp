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
    const static int N=1e3+40;
    vector<int> adj[N];
    int leaf[N];
    vector<int> leaf_nodes;
    int vis[N];
    int dfs(int s,int distance){
        vis[s]=1;
        if(distance<0) return 0;
        int g=0;
        int tot=0;
        for(int x:adj[s]){
            if(!vis[x]){
               tot+=dfs(x,distance-1);
                g=1;
            }
        }
        if(leaf[s]) return 1;
        return tot;
        
    }
    int gx=1;
    void make_tree(TreeNode * root,int p=0){
        if(!root) return;
        gx++;
        if(p){
            adj[p].push_back(gx);
            adj[gx].push_back(p);
        }
        if(!root->left && !root->right){
            // leaf[gx]=1;
            leaf_nodes.push_back(gx);
            return;
        }
        
        int g=gx;
        make_tree(root->left,g);
        make_tree(root->right,g);
    }
    int countPairs(TreeNode* root, int distance) {
        make_tree(root);
        int good_leaf_pair=0;
        for(int i:leaf_nodes){
            
            memset(vis,0,sizeof(vis));
            int good_pairs=dfs(i,distance);
            leaf[i]=1;
            good_leaf_pair+=good_pairs; 
        }
        return good_leaf_pair;
        
    }
};
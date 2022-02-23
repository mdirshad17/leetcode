/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    set<Node*> vis;
    map<Node*,Node*> mp;
    set<Node*> done;
    Node * solve(Node * node)
    {     if(!node)return NULL;
          Node * tt=new Node(node->val);
          vis.insert(node);
          for(auto x:node->neighbors){
             if(vis.count(x))continue;
              solve(x);
          }
        return mp[node]=tt;
    }
    Node * builder(Node * root){
        if(!root)return NULL;
        vis.insert(root);
        for(auto x:root->neighbors){
            if(vis.count(x)){
                mp[root]->neighbors.push_back(mp[x]);
                // mp[x]->neighbors.push_back(mp[root]);
            }else{
                builder(x);
                 mp[root]->neighbors.push_back(mp[x]);
                // mp[x]->neighbors.push_back(mp[root]);
            }
        }
        return mp[root];
    }
    Node* cloneGraph(Node* node) {
          solve(node);
          vis.clear();
        return builder(node);
    }
};
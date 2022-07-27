/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void po(Node * root,vector<int> & ans){
        if(root==nullptr)return;
        ans.push_back(root->val);
        // how to acces child
        for(int i=0;i<root->children.size();i++){
            Node * child=root->children[i];
            po(child,ans);
        }
        
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        po(root,ans);
        return ans;
    }
};
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
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>> RES;
         if(root==NULL)return {};
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            vector<int> res;
            int ns=q.size();
            while(ns--){
                Node * tp=q.front();
                q.pop();
                res.push_back(tp->val);
                for(Node * ch:tp->children){
                    q.push(ch);
                }
            }
            RES.push_back(res);
        }
        return RES;
    }
};
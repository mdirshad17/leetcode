/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return root;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int ns=q.size();
            vector<Node*> v;
            while(ns--){
                Node * front=q.front();
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                v.push_back(front);
            }
            ///
            for(int i=0;i<v.size();i++){
                if((i+1)<v.size()){
                    v[i]->next=v[i+1];
                }else v[i]->next=NULL;
            }
        }
        return root;
    }
};
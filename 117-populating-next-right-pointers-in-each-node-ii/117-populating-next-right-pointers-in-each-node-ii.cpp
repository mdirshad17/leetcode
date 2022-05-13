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
    #define TreeNode Node
    void solve(TreeNode * root,TreeNode * p){
        if(!root)return;
        TreeNode * g=p;
        TreeNode * f=NULL;
        while(g){
            TreeNode * a=g->left;
            if(a && a!=root && a!=p->left){
                f=a;
                break;
            }
            TreeNode * b=g->right;
            if(b && b!=p->left  && b!=root){
                f=b;
                break;
            }
            g=g->next;
        }
        root->next=f;
        solve(root->right,root);
        
        solve(root->left,root);
        
        return;
    }
    Node* connect(Node* root) {
        if(!root)return NULL;
        solve(root,NULL);
        // root->next=NULL;
        return root;
    }
};
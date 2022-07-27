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

class Solution
{
    public:
       	// Cf connecting function
        void CF(Node *root, Node *parent)
        {
            if (root == NULL) return;
            if(parent){
                if(root==parent->left){
                    root->next=parent->right;
                }else{
                    if(parent->next){
                        root->next=parent->next->left;
                    }else root->next=NULL;
                }
            }else root->next=NULL;
            
            CF(root->left,root);
            CF(root->right,root);
        }
    Node* connect(Node *root)
    {
        if (root == NULL) return root;
        CF(root, NULL);
        return root;
    }
};
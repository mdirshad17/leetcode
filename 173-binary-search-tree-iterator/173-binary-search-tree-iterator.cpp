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
class BSTIterator {
public:
    vector<TreeNode*> N;
    int s=0;
    void populate(TreeNode * root){
        if(!root){
            return;
        }
        populate(root->left);
        N.push_back(root);
        populate(root->right);
        
    }
    BSTIterator(TreeNode* root) {
        populate(root);
    }
    
    int next() {
        return N[s++]->val;
    }
    
    bool hasNext() {
        return (s<N.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
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
class FindElements {
public:
    TreeNode * tree=NULL;
    TreeNode * getTree(TreeNode * root,int val){
        if(!root) return NULL;
        TreeNode* node=new TreeNode(val);
        node->left=getTree(root->left,(2*val)+1);
        node->right=getTree(root->right,(2*val)+2);
        return node;
    }
    FindElements(TreeNode* root) {
        tree=getTree(root,0);
    }
    bool search(TreeNode * root,int val){
        if(!root) return false;
        if(root->val==val) return true;
        if(search(root->left,val)){
            return true;
        }
        return search(root->right,val);
    }
    bool find(int target) {
        return search(tree,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
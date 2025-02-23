/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int pi=0;
    TreeNode constructTree(int[] preorder,int l,int r,int []postorder){
            if(l>r) return null;
            if(l==r) {
                return new TreeNode(preorder[pi++]);
                }
            TreeNode root=new TreeNode(preorder[pi]);
            int lpe=r+1;
             pi++;
            for(int i=l;i<=r;i++){
                if(postorder[i]==preorder[pi]){
                    lpe=i;
                    break;
                }
            }
            // System.out.println(pi);
            root.left=constructTree(preorder,l,lpe,postorder);
            root.right=constructTree(preorder,lpe+1,r-1,postorder);
            return root;
    }
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        // Integer pi=0;
        return constructTree(preorder,0,postorder.length-1,postorder);
    }
}
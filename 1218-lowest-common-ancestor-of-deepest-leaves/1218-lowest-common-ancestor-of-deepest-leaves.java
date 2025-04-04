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
    int maxDeep;
    int cnt;
    void solve(TreeNode root,int dep){
        if(root==null) return;
        if(dep>maxDeep){
            cnt=1;
            maxDeep=dep;
        }else if(dep==maxDeep){
            cnt++;
        }
        solve(root.left,dep+1);
        solve(root.right,dep+1);
    }
    TreeNode  res;
    int getNode(TreeNode  root,int dep){
        if(root==null) return 0;
        int op1=getNode(root.left,dep+1);
        int op2=getNode(root.right,dep+1);
        int cntH=op1+op2+(dep==maxDeep?1:0);
        if(cntH==cnt && res.val==-1){
            res=root;
        }
        if(dep==maxDeep) return 1;
        return cntH;
        }
        
    public TreeNode lcaDeepestLeaves(TreeNode root) {
       
        res=new TreeNode(-1);
        solve(root,0);
        System.out.print(cnt+" "+maxDeep);
         getNode(root,0);
         return res;
    }
}
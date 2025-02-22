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
    TreeNode solve(int l,int r,String tree,int lv){
        if(l>r) return null;
        // left solve(l+1,x);
        // right solve(x+1,r);
        int x=r+1;
        int li=r+1;
        int val=0;
        while(l<=r && tree.charAt(l)!='-'){
            val=(val*10)+(tree.charAt(l)-'0');
            l++;
        }
        int len=r;
        int cnt=0;
        for(int i=l;i<=r;i++){
                if(tree.charAt(i)=='-'){
                    cnt++;
                }else{
                    if(cnt==lv+1){
                    if(li==r+1){
                        li=i;
                    }else{
                        len=i-(cnt+1);
                        x=i;
                        break;
                    }
                }    
                    cnt=0;
            }
        }

        TreeNode root=new TreeNode(val);
        root.left=solve(li,len,tree,lv+1);
        root.right=solve(x,r,tree,lv+1);
        return root;
    }
    public TreeNode recoverFromPreorder(String traversal) {
        // HashMap<Integer,Integer> mp=new HashMap<>();
        // int cnt=0;
        // for(int i=0;i<traversal.length();i++){
        //     if(traversal.charAt(i)=='-'){
        //             cnt++;
        //     }else{
        //         mp.put((traversal.charAt(i)-'0'),cnt);
        //         cnt=0;
        //     }
        // }
        int n=traversal.length();
        return solve(0,n-1,traversal,0);

    }
}
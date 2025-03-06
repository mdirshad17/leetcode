class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n=grid.length;
        int vis[]=new int[n*n];
        int res[]=new int[2];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[grid[i][j]-1]++;
            }
        }
        int idx=0;
        for(int i=0;i<n*n;i++){
            if(vis[i]==0){
                res[1]=i+1;
            }else if(vis[i]==2){
                res[0]=i+1;
            }
        }
        return res;
    }
}
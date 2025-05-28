class Solution {
    int dp[][];
    int solve(int l,int r){
       int ans=Integer.MAX_VALUE;
       if(l>=r) return 0;
       if(dp[l][r]!=-1) return dp[l][r];
       for(int i=l;i<=r;i++){
        int sum=i+Math.max(solve(l,i-1),solve(i+1,r));
         ans=Math.min(ans,sum);
       }
       return dp[l][r]=ans;
       
    }
    public int getMoneyAmount(int n) {
        dp=new int[n+5][n+5];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(1,n);
    }
}
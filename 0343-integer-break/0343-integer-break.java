class Solution {
    int dp[][];
    int solve(int n,int done){
        if(n<=1) return 1;
        if(dp[n][done]!=-1) return dp[n][done];
        int ans=1;
        for(int i=1;i<=(done==1?n:n-1);i++){
            ans=Math.max(ans,i*solve(n-i,1));
        }
        return dp[n][done]=ans;
    }
    public int integerBreak(int n) {
        dp=new int[n+2][2];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(n,0);
    }
}
class Solution {
public:
    const static int N=1e5+10;
    int dp[N];
    int solve(int n){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
         int ans=0;
         for(int i=1;i*i<=n;i++){
             int l=solve(n-(i*i));
             if(l==0){
                 ans=1;
                 
             }
             if(ans)break;
         } 
        return dp[n]=ans;
    }
    bool winnerSquareGame(int n) 
    {
        memset(dp,-1,sizeof(dp));
      return solve(n);    
    }
};
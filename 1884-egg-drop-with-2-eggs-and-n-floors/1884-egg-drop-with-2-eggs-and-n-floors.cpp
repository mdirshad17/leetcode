class Solution {
public:
    int dp[1005];
    int solve(int n){
       if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
       int ans=INT_MAX;
       for(int i=1;i<n;i++){
           int op1=i-1;
           int op2=solve(n-i);
           ans=min(ans,max(op1,op2));
       } 
        return dp[n]=1+ans;
    }
    int twoEggDrop(int n) {
      
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
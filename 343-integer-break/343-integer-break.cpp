class Solution {
public:
    int dp[60];
    int solve(int n){
        // cout<<n<<endl;
        if(n==0||n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++){
            int l=i*solve(n-i);
            ans=max(ans,l);
        }
        return dp[n]=ans;
        
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        if(n==3||n==2)return (n-1);
        return solve(n);
    }
};
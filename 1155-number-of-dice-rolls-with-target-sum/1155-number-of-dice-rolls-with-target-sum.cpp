class Solution {
public:
    int dp[35][1005];
    #define M 1000000007
    #define ll long long
    int solve(int s,int n,int k,int sum){
        if(s>=n)return (sum==0);
        if(sum<0)return 0;
        if(dp[s][sum]!=-1)return dp[s][sum];
        ll ans=0;
        for(int i=1;i<=k;i++){
            ans+=solve(s+1,n,k,sum-i);
            ans=ans%M;
        }
        return dp[s][sum]=ans%M;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,k,target);
    }
};
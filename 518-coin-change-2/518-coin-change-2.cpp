class Solution {
public:
    int dp[5005][305];
    int solve(int s,int n,int sum,vector<int> & v){
        if(sum==0)return 1;
        if(s>=n||sum<0)return 0;
        if(dp[sum][s]!=-1)return dp[sum][s];
        int op1=solve(s,n,sum-v[s],v);
        int op2=solve(s+1,n,sum,v);
        return dp[sum][s]=(op1+op2);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,coins.size(),amount,coins);
    }
};
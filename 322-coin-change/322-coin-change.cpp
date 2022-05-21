class Solution {
public:
    int dp[15][10005];
    int solve(int s,int n,vector<int> & coins,int sum){
        
        if(sum==0)return 0;
        if(s>=n||sum<0) return INT_MAX/100;
        if(dp[s][sum]!=-1)return  dp[s][sum];
        int op1=1+solve(s,n,coins,sum-coins[s]);
        int op2=solve(s+1,n,coins,sum);
        return  dp[s][sum]=min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int n=coins.size();
        int l=solve(0,n,coins,amount);
        if(l>amount)l=-1;
        return l;
    }
};
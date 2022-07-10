class Solution {
public:
    int dp[1005];
    int solve(int s,vector<int> & v){
        if(s>=v.size())return 0;
        if(dp[s]!=-1)return dp[s];
        int op1=v[s]+solve(s+1,v);
        int op2=v[s]+solve(s+2,v);
        return dp[s]=min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int op1=solve(0,cost);
        int op2=solve(1,cost);
        return min(op1,op2);
    }
};
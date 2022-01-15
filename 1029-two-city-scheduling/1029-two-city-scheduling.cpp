class Solution {
public:
    int dp[105][55];
    int solve(int s,int n,vector<vector<int>> & costs,int m){
        if(s>=n){
            if(m==0)return 0;
            return INT_MAX/100; 
        }
        if(m<0)return INT_MAX/100;
        if(dp[s][m]!=-1) return dp[s][m];
        int op1=solve(s+1,n,costs,m-1)+costs[s][0];
        int op2=solve(s+1,n,costs,m)+costs[s][1];
        return dp[s][m]=min(op1,op2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,costs,n/2);
    }
};
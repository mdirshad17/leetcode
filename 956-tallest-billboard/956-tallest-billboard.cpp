class Solution {
public:
    int dp[25][10005];
    int solve(int s,int n,vector<int> & v,int h){
        if(s>=n){
            if(h==5000) return 0;
            return INT_MIN/100;
        }
        if(dp[s][h]!=-1) return dp[s][h];
        int op1=v[s]+solve(s+1,n,v,h+v[s]);
        int op2=solve(s+1,n,v,h-v[s]);
        int op3=solve(s+1,n,v,h);
        return dp[s][h]=max({op1,op2,op3});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return solve(0,rods.size(),rods,5000);
    }
};
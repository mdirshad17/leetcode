class Solution {
public:
    int dp[6005][35];
    int solve(int s,int n,vector<int> &stones,int sum){
        if(s>=n){
            return abs(sum);
        }
        if(dp[3000+sum][s]!=-1)return dp[sum+3000][s];
        int op1=solve(s+1,n,stones,sum+stones[s]);
        int op2=solve(s+1,n,stones,sum-stones[s]);
        
        return  dp[3000+sum][s]=min(op1,op2);
    }
    int lastStoneWeightII(vector<int>& stones) {
         memset(dp,-1,sizeof(dp));
         return solve(0,stones.size(),stones,0);
    }
};
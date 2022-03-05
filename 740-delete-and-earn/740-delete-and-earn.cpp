class Solution {
public:
    const static int N=1e4+5;
    int cnt[N];
    int dp[N];
    int solve(int s){
        if(s>=N-2)return 0;
        if(dp[s]!=-1)return dp[s];
        int op1=cnt[s]+solve(s+2);
        int op2=solve(s+1);
        return dp[s]=max(op1,op2);
    }
    int deleteAndEarn(vector<int>& nums) {
        for(int x:nums){
            cnt[x]+=x;
        }
        memset(dp,-1,sizeof(dp));
        return solve(1);
    }
};
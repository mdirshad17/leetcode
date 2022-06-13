class Solution {
public:
    int n;
    int dp[205][205];
    int solve(int r,int c,vector<vector<int>>& t){
        if(r==n)return 0;
        if(dp[r][c]!=-1)return dp[r][c];
        int op1=t[r][c]+solve(r+1,c,t);
        int op2=t[r][c]+solve(r+1,c+1,t);
        return dp[r][c]=min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& t) {
       memset(dp,-1,sizeof(dp)); 
       n=t.size();
       return solve(0,0,t); 
    }
};
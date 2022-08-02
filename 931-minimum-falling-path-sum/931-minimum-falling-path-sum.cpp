class Solution {
public:
    int dr[3]={1,1,1};
    int dc[3]={-1,0,1};
    int dp[105][105];
    int solve(int rn,int cn,vector<vector<int>>& matrix){
        int n=matrix.size();
        if(rn>=n)return 0;
        if(cn>=n||cn<0)return INT_MAX/10;
        if(dp[rn][cn]!=-1)return dp[rn][cn];
        int ans=INT_MAX/10;
        // for(int i=0;i<3;i++){
        //     int l=matrix[rn][cn]+solve(rn+dr[i],cn+dc[i],matrix);
        //     ans=min(ans,l);
        // }
        int op1=matrix[rn][cn]+solve(rn+1,cn-1,matrix);
        int op2=matrix[rn][cn]+solve(rn+1,cn,matrix);
        int op3=matrix[rn][cn]+solve(rn+1,cn+1,matrix);
        ans=min({op1,op2,op3});
        return dp[rn][cn]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
     
        memset(dp,-1,sizeof(dp));
        int n=matrix.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int l=solve(0,i,matrix);
            ans=min(ans,l);
        }
        return ans;
    }
};
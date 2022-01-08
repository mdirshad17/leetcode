class Solution {
public:
    int n,m;
    int dy[3]={-1,0,1};
    int dp[80][80][80];
    int solve(int s,int c1,int c2,vector<vector<int> > & grid){
        if(s>=n||c1<0||c2<0||c1>=m||c2>=m){
            return 0;
        }
        if(dp[s][c1][c2]!=-1) return dp[s][c1][c2];
        int sum=grid[s][c1]+grid[s][c2];
        if(c1==c2) sum-=grid[s][c1];
        int ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int l=solve(s+1,c1+dy[i],c2+dy[j],grid);
                ans=max(ans,l);
            }
            
        }
        return dp[s][c1][c2]=sum+ans;
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,grid);
    }
};
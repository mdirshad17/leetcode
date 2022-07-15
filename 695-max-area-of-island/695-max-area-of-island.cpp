class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0)return 0;
        int l=1;
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int X=i+dx[k];
            int Y=j+dy[k];
            l+=dfs(X,Y,grid);
        }
        return l;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int l=dfs(i,j,grid);
                    ans=max(ans,l);
                }
            }
        }
        return ans;
    }
};
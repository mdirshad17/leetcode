class Solution {
public:
    int n,m;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void dfs(int r,int c,vector<vector<char>>& G){
        if(r<0||r>=n||c<0||c>=m||G[r][c]=='0')return;
        G[r][c]='0';
        for(int i=0;i<4;i++){
            int X=r+dr[i];
            int Y=c+dc[i];
            dfs(X,Y,G);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
            int ans=0;
            n=grid.size();
            m=grid[0].size();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1'){
                        dfs(i,j,grid);
                        ans++;
                    }
                }
            }
        return ans;
    }
};
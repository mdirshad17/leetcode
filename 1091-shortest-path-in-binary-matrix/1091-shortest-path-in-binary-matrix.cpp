class Solution {
public:
    #define      pii pair<int,int>
    int dx[8]={-1,1,0,0,-1,-1,1,1};
    int dy[8]={0,0,-1,1,-1,1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pii> q;
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1)return -1;
        q.push({0,0});
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int len=1;
        while(q.size()){
            int ns=q.size();
            while(ns--){
                pii d=q.front();
                q.pop();
                int x=d.first;
                int y=d.second;
                if((x==n-1) && (y==m-1))return len;
                vis[x][y]=1;
                for(int i=0;i<8;i++){
                    int X=x+dx[i];
                    int Y=y+dy[i];
                    if(X<0||Y<0||X>=n||Y>=n||vis[X][Y]==1||grid[X][Y])continue;
                    q.push({X,Y});
                    vis[X][Y]=1;
                }
            }len++;
        }
        return -1;
    }
};
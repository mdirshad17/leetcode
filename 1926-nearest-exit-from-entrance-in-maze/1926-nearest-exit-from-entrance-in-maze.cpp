class Solution
{
    public:
#define pii pair<int, int>
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
        int nearestExit(vector<vector < char>> &maze, vector< int > &E)
        {

            int n = maze.size();
            int m = maze[0].size();
            int vis[n][m];
            memset(vis, 0, sizeof(vis));
            int lv = 0;
            queue<pii> q;
            q.push({ E[0],
                E[1] });
            vis[E[0]][E[1]] = 1;
            while(q.size()){
                int ns=q.size();
                while(ns--){
                    int xc=q.front().first;
                    int yc=q.front().second;
                    // cout<<xc<<" "<<yc<<endl;
                    q.pop();
                    int f=1;
                    if(xc==E[0] && yc==E[1])f=0;
                    if(f && (xc==0||xc==n-1||yc==0||yc==m-1))return lv;
                    for(int i=0;i<4;i++){
                        int X=xc+dx[i];
                        int Y=yc+dy[i];
                        if(X>=0 && X<n && Y>=0 && Y<m && !vis[X][Y] && maze[X][Y]=='.'){
                            vis[X][Y]=1;
                            q.push({X,Y});
                        }
                    }
                }
                lv++;
            }
            return -1;
        }
};
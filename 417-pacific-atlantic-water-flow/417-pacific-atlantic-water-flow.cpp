class Solution {
public:
    int p[205][205];
    int a[205][205];
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void dfs(int r,int c,vector<vector<int>>& h,int vis[][205],int val){
        if(r<0||c<0||r>=h.size()||c>=h[0].size()||vis[r][c]||val>h[r][c])return;
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int R=r+dr[i];
            int C=c+dc[i];
            dfs(R,C,h,vis,h[r][c]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
          int n=h.size();
          int m=h[0].size();
          for(int i=0;i<n;i++){
              if(p[i][0])continue;
              dfs(i,0,h,p,INT_MIN);
          }
        for(int i=0;i<m;i++){
            if(p[0][i])continue;
            dfs(0,i,h,p,INT_MIN);
        }
        for(int i=0;i<n;i++){
            if(a[i][m-1])continue;
            dfs(i,m-1,h,a,INT_MIN);
        }
        for(int i=0;i<m;i++){
            if(a[n-1][i])continue;
            dfs(n-1,i,h,a,INT_MIN);
        }
         vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && p[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
            
    }
};
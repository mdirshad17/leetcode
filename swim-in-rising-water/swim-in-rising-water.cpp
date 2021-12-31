class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int swimInWater(vector<vector<int>>& grid) 
    {
          int n=grid.size();  
          int dp[n][n];
          memset(dp,1,sizeof(dp));
          set<vector<int>> st;
          st.insert({grid[0][0],0,0});
          dp[0][0]=grid[0][0];
          while(st.size()){
              auto it=(st.begin());
              int w=(*it)[0];
              int xi=(*it)[1];
              int yi=(*it)[2];
              st.erase(it);
              for(int i=0;i<4;i++){
                  int X=xi+dx[i];
                  int Y=yi+dy[i];
                  if(X>=0 && X<n && Y>=0 && Y<n){
                      int g=max(w,grid[X][Y]);
                      if(dp[X][Y]>g){
                          st.erase({dp[X][Y],X,Y});
                          dp[X][Y]=g;
                          st.insert({dp[X][Y],X,Y});
                      }
                  }
              }
          }
         return dp[n-1][n-1];
        
    }
};
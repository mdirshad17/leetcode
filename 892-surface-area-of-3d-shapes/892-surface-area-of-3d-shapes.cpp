class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int surfaceArea(vector<vector<int>>& grid) {
          int n=grid.size();
          int ans=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  ans+=2*(grid[i][j]>0);
                  for(int k=0;k<4;k++){
                      int xi=i+dx[k];
                      int yi=j+dy[k];
                      if(xi<0||xi>=n||yi<0||yi>=n){
                          ans+=grid[i][j];
                      }else {
                          int num=grid[xi][yi];
                          if(num<grid[i][j]){
                              ans+=abs(num-grid[i][j]);
                          }
                      }
                  }
              }
              
          }
        return ans;
    }
};
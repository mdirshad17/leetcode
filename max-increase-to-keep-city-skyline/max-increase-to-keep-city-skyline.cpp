class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
          int n=grid.size();
          vector<int> rw(n,0);
          vector<int> cw(n,0);
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  rw[i]=max(rw[i],grid[i][j]);
                  cw[j]=max(cw[j],grid[i][j]);
              }
          }
        int ans=0;
        for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                 ans+=abs(grid[i][j]-min(rw[i],cw[j]));
              }
          }
        return ans;
        
    }
};
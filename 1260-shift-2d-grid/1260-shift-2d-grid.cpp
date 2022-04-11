class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
         int n=grid.size();
         int m=grid[0].size();
         for(int l=1;l<=k;l++){
             vector<vector<int>> gr=grid;
             for(int i=0;i<n;i++){
                 for(int j=0;j<m;j++){
                     if(j==m-1){
                         gr[(i+1)%n][(j+1)%m]=grid[i][j];
                     }else{
                         gr[i][j+1]=grid[i][j];
                         // cout<<i<<
                     }
                 }
             }
             // for(int i=0;i<n;i++){
             //     for(int j=0;j<m;j++){
             //         cout<<gr[i][j]<<" ";
             //     }cout<<endl;
             // }
             grid=gr;
         }
        return grid;
    }
};
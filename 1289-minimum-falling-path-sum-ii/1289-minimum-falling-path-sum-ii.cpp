class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int l[n];
        int r[n];
        l[0]=grid[0][0];
        for(int i=1;i<n;i++){
            l[i]=min(l[i-1],grid[0][i]);
        }
        r[n-1]=grid[0][n-1];
        for(int i=n-2;i>=0;i--){
            r[i]=min(r[i+1],grid[0][i]);
        }
        for(int i=1;i<n;i++){
            
            for(int j=0;j<n;j++){
                int lmin=(j>0?l[j-1]:INT_MAX/100);
                int rmin=(j+1<n?r[j+1]:INT_MAX/100);
                int add=min(lmin,rmin);
                grid[i][j]+=add;
            }
            l[0]=grid[i][0];
        for(int j=1;j<n;j++){
            l[j]=min(l[j-1],grid[i][j]);
        }
        r[n-1]=grid[i][n-1];
        for(int j=n-2;j>=0;j--){
            r[j]=min(r[j+1],grid[i][j]);
        }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,grid[n-1][i]);
        }
        return ans;
    }
};
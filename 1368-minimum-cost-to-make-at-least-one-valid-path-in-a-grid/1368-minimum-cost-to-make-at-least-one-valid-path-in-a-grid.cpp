class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    #define pii pair<int,int>
    
    int minCost(vector<vector<int>>& grid) {
           int n=grid.size();
           int m=grid[0].size();
           int dp[n][m];
           memset(dp,1,sizeof(dp));
           
           priority_queue<pii,vector<pii>,greater<pii>> pq;
           pq.push({0,0});
           dp[0][0]=0;
           while(pq.size()){
               auto tp=pq.top();
               pq.pop();
               int l=grid[tp.first][tp.second]-1;
               for(int i=0;i<4;i++){
                   int wt=(l!=i);
                   int X=tp.first+dx[i];
                   int Y=tp.second+dy[i];
                   if(X>=0 && X<n && Y>=0 && Y<m && dp[X][Y]>wt+dp[tp.first][tp.second]){
                       dp[X][Y]=wt+dp[tp.first][tp.second];
                       pq.push({X,Y});
                     
                   }
               }
           }
        return dp[n-1][m-1];
    }
};
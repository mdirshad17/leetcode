class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
           int n=grid.size();
           int m=grid[0].size();
           int dp[n][m];
           memset(dp,1,sizeof(dp));
           
           deque<pair<int,int>> dq;
           dq.push_front({0,0});
           dp[0][0]=0;
           while(dq.size()){
               auto tp=dq.front();
               dq.pop_front();
               int l=grid[tp.first][tp.second]-1;
               for(int i=0;i<4;i++){
                   int wt=(l!=i);
                   int X=tp.first+dx[i];
                   int Y=tp.second+dy[i];
                   if(X>=0 && X<n && Y>=0 && Y<m && dp[X][Y]>wt+dp[tp.first][tp.second]){
                       dp[X][Y]=wt+dp[tp.first][tp.second];
                       if(wt==0)dq.push_front({X,Y});
                       else dq.push_back({X,Y});
                   }
               }
           }
        return dp[n-1][m-1];
    }
};
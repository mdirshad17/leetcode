class Solution {
public:
    #define vi vector<int>
    int minimumEffortPath(vector<vector<int>>& h) {
       int n=h.size();
       int m=h[0].size(); 
       int dp[n][m];
       memset(dp,1,sizeof(dp));
       dp[0][0]=0;
        set<vi> st;
        // wt x y
        st.insert({0,0,0});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(st.size()){
            auto it=st.begin();
            int wt=(*it)[0];
            int x=(*it)[1];
            int y=(*it)[2];
            st.erase(it);
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m)continue;
                
                int diff=abs(h[x][y]-h[nx][ny]);
                int gt=max(wt,diff);
                if(gt<dp[nx][ny]){
                    st.erase({dp[nx][ny],nx,ny});
                    dp[nx][ny]=gt;
                    st.insert({dp[nx][ny],nx,ny});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return dp[n-1][m-1];
    }
};
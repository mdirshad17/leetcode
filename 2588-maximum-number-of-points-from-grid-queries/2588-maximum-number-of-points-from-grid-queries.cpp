class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>> qrs;
        int n=queries.size();
        for(int i=0;i<n;i++){
            qrs.push_back({queries[i],i});
        }
        sort(qrs.begin(),qrs.end(),[](pair<int,int> &a,pair<int,int> &b){
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        });
        set<vector<int> > st;
        int dp[1005][1005];
        memset(dp,1,sizeof(dp));
        dp[0][0]=grid[0][0];
        st.insert({dp[0][0],0,0});
        n=grid.size();
        int m=grid[0].size();
        while(st.size()){
            auto it=st.begin();
            int wt=(*it)[0];
            int u=(*it)[1];
            int v=(*it)[2];
            st.erase(it);
            for(int i=0;i<4;i++){
                int X=u+dx[i];
                int Y=v+dy[i];
                if(X>=0 && X<n && Y>=0 && Y<m){
                    int wth=max(wt,grid[X][Y]);
                    if(wth<dp[X][Y]){
                        st.erase({dp[X][Y],X,Y});
                        dp[X][Y]=wth;
                        st.insert({dp[X][Y],X,Y});
                    }
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]+=1;
                res.push_back(dp[i][j]);
            }
        }
        sort(res.begin(),res.end());
        int i=0;
        for(int j=0;j<qrs.size();j++){
            while(i<res.size() && res[i]<=qrs[j].first){
                i++;
            }
            queries[qrs[j].second]=i;
        }
        return queries;
    }
};
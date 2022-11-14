class Solution {
public:
    vector<int> adj[1005];
    int vis[1005];
    int dfs(int s){
        vis[s]=1;
        int ans=1;
        for(auto x:adj[s]){
            if(vis[x])continue;
            ans+=dfs(x);
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
                  if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                      adj[i].push_back(j);
                      adj[j].push_back(i);
                  }
              }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            int n=dfs(i);
            ans+=(n-1);
        }
        return ans;
    }
};
class Solution {
public:
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n=scores.size();  
        vector<int> adj[n];
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end(),[&scores](int a,  int b){
              return (scores[a]>scores[b]); 
            });
        }
        // return 0;
        int ans=-1;
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            for(int j=0;j<min(3,(int)adj[u].size());j++){
                int nb=adj[u][j];
                if(nb==v)continue;
                for(int k=0;k<min(3,(int)adj[v].size());k++){
                    int nbx=adj[v][k];
                    if(nbx==u||nbx==nb)continue;
                    int sumh=scores[u]+scores[v]+scores[nb]+scores[nbx];
                    ans=max(ans,sumh);
                }
            }
        }
        return ans;
        
        
    }
};
class Solution {
public:
    vector<vector<int> > adj;
    vector<int> parent, rnk;
int getp(int u) { return (u == parent[u] ? u : (parent[u] = getp(parent[u])));}
int connect(int u, int v) {
  u = getp(u), v = getp(v);
  if (u == v) return 1;
  if (rnk[u] < rnk[v]) swap(u, v);
  parent[v] = u;
  rnk[u] += rnk[v];
  return 0;
}
    int minCostConnectPoints(vector<vector<int>>& p) {
       int n=p.size();
        parent.clear();
        parent.resize(n+1);
        rnk.clear();
        rnk.assign(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=i+1;j<n;j++){
                int dist=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                adj.push_back({dist,i,j});
                // adj.push_back({dist,j,i});
            }
        }
        // return 0;
        sort(adj.begin(),adj.end());
        int ans=0;
        int cnt=0;
        
        for(auto x:adj){
            
            int w=x[0];
            int v=x[1];
            int u=x[2];
            int l=connect(u,v);
            // cout<<l<<endl;
            if(l==0){
                ans+=w;
                cnt++;
            }
            if(cnt==n-1)return ans;
        }
        return ans;
    }
};
class Solution {
public:
    const static int N=2e3+5;
    int vis[N];
    int st[N];
    vector<int> adj[N];
    vector<int> v;
    int dfs(int s) {
	vis[s] = 1;
	st[s] = 1;
	for (auto x : adj[s]) {
		if (vis[x] && st[x]) {
			return true;
		} else if (!vis[x] && dfs(x)) {
			return true;
		}
	}
	v.push_back(s);
	st[s] = 0;
	return false;
}
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        for(auto x:p){
            int u=x[0];
            int v=x[1];
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int l=dfs(i);
                if(l)return {};
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
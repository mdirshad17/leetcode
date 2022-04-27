class Solution {
public:
    vector<int> adj[100005];
    int vis[100005];
    vector<int> v;
    string f;
    string c;
    void dfs(int s){
        c.push_back(f[s]);
        vis[s]=1;
        v.push_back(s);
        for(auto x:adj[s]){
            if(vis[x])continue;
            dfs(x);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
        f=s;
        for(auto x:p){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int n=s.size();
        string res=s;
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            v.clear();
            c.clear();
            dfs(i);
            sort(v.begin(),v.end());
            sort(c.begin(),c.end());
            for(int i=0;i<v.size();i++){
                res[v[i]]=c[i];
            }
        }
        return res;
    }
};
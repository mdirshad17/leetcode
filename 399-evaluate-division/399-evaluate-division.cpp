class Solution {
public:
    double adj[50][50];
    double points[50][50];
    int vis[50];
    int n;
    void dfs(int p,int s,double val){
        // cout<<s<<" "<<val<<endl;
        vis[s]=1;
        points[p][s]=val;
        for(int x=0;x<n;x++){
            if(!vis[x] && adj[s][x]){
                dfs(p,x,(val*adj[s][x]));
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& queries)     {
        map<string,int> mp;
        int s=0;
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                points[i][j]=-1.0;
            }
        }
        
        for(int i=0;i<eq.size();i++){
            string a=eq[i][0];
            string b=eq[i][1];
            if(!mp.count(a)){
                mp[a]=s++;
            }
            if(!mp.count(b)){
                mp[b]=s++;
            }
            int n1=mp[a];
            int n2=mp[b];
            adj[n1][n2]=val[i];
            adj[n2][n1]=1.0/val[i];
            // cout<<adj[n1][n2]<<" "<<adj[n2][n1]<<endl;
        }
        n=s;
        for(int i=0;i<s;i++){
            // cout<<endl;
            memset(vis,0,sizeof(vis));
            dfs(i,i,1.0);
        }
        vector<double> res;
        for(auto x:queries){
            string a=x[0];
            string b=x[1];
            if(!mp.count(a)||!mp.count(b)){
                res.push_back(-1);
            }else{
                int n1=mp[a];
                int n2=mp[b];
                // cout<<n1<<" "<<n2<<" "<<points[n1][n2]<<endl;
                res.push_back(points[n1][n2]);
            }
        }
        return res;
        
    }
};
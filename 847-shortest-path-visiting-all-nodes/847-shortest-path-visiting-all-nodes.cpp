class Solution {
public:
    int dist[14][14];
    int MASK;

    void ppo(vector<vector<int>>& adj){
        memset(dist,-1,sizeof(dist));
        int n=adj.size();
        MASK=(1<<n)-1;
        for(int i=0;i<n;i++){
            int sn=i;
            queue<int> q;
            q.push(i);
            int l=0;
            dist[sn][sn]=0;
            while(q.size()){
                int ns=q.size();
                while(ns--){
                    int node=q.front();
                    q.pop();
                   
                    for(auto x:adj[node]){
                        if(dist[sn][x]==-1){
                            q.push(x);
                            dist[sn][x]=1+l;
                        }
                    }
                }l++;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dist[i][j]<<" ";
        //     }cout<<endl;
        // }
       
    }
    int dp[15][8192];
    int cnt=0;
    int solve(int mask,int node,int n){
        if(mask==MASK){
            return 0;
        }
        cnt++;
        if(dp[node+1][mask]!=-1)return dp[node+1][mask];
        int ans=100000;
        if(node==-1){
            for(int i=0;i<n;i++){
                ans=min(ans,solve((mask|(1<<i)),i,n));
            }
        }else{
            for(int j=0;j<n;j++){
                if((mask&(1<<j)))continue;
                ans=min(ans,dist[node][j]+solve((mask|(1<<j)),j,n));
            }
        }
        return dp[node+1][mask]=ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        ppo(graph);
        memset(dp,-1,sizeof(dp));
        // cout<<MASK<<endl;
        int f=solve(0,-1,graph.size());
        cout<<cnt<<endl;
        cnt=0;
        return f;
        
    }
};
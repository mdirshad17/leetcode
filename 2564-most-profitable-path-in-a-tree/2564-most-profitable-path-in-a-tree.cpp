class Solution {
public:
    const static int N=1e5+5;
    vector<int> adj[N];
    int alice[N];
    int bobs[N];
    int pr[N];
    void fromAlice(int u,int p=-1,int t=0){
            alice[u]=t;
            pr[u]=p;
            for(int x:adj[u]){
            if(x==p){
                continue;
            }
            fromAlice(x,u,t+1);
        }
    }
    int solve(int node,int p,vector<int>& amount){
           int contri=amount[node];
           if(alice[node]>bobs[node]){
            contri=0;
           }else if(alice[node]==bobs[node]){
              contri=contri/2;
           }
            int ans=INT_MIN;
            int hasChild=0;
            for(int x:adj[node]){
              if(x==p)continue;
              hasChild=1;
              ans=max(ans,solve(x,node,amount));  
        }
        return hasChild?ans+contri:contri;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(pr,-1,sizeof(pr));
        int time=0;
        fromAlice(0);
        memset(bobs,1,sizeof(bobs));
        while(bob!=-1){
           bobs[bob]=time++;
           bob=pr[bob];     
        }
        return solve(0,-1,amount);
    }
};
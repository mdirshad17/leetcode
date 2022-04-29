class Solution {
public:
    int bp[105];
    vector<vector<int>> adj;
    int bps(int s,int l){
        bp[s]=l;
        int f=1;
        for(auto x:adj[s]){
            if(bp[x]>=0){
                if(bp[x]==bp[s])return 0;
            }else{
                f=(f&bps(x,1-l));
                if(f==0)return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        memset(bp,-1,sizeof(bp));
        int n=graph.size();
       adj=graph;
        int ans=1;
        for(int i=0;i<n;i++){
            if(bp[i]>=0)continue;
            ans=(ans&(bps(i,0)));
            if(ans==0)return 0;
        }
        return 1;
    }
};
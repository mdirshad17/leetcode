class Solution {
    int par[];
    int node[];
    int numEdges[];
    int get(int u){
        if(u==par[u]) return u;
        return par[u]=get(par[u]);
    }
    void add(int u,int v){
        u=get(u);
        v=get(v);
        if(u==v){
            numEdges[u]+=1;
            return;
        }
        par[v]=u;
        node[u]+=node[v];
        numEdges[u]+=1+numEdges[v];
    }
    public int countCompleteComponents(int n, int[][] edges) {
        par=new int[n];
        node=new int[n];
        numEdges=new int[n];
        for(int i=0;i<n;i++){
            par[i]=i;
            node[i]=1;
            numEdges[i]=0;
        }
        for(int i=0;i<edges.length;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            add(u,v);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // System.out.println(i+" "+par[i]+" "+numEdges[i]+" "+node[i]);
            int cnt=node[i];
            int nd=(cnt*(cnt-1)/2);
            if(i==par[i] && numEdges[i]>=nd){
                ans++;
            }
        }
        return ans;
    }
}
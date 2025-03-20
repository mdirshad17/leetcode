class Solution {
    int parent[];
    int andR[];
    int getP(int u){
        if(u==parent[u]) return u;
        return parent[u]=getP(parent[u]);
    }
    void getUnion(int a,int b,int val){
        a=getP(a);
        b=getP(b);
        parent[b]=a;
        andR[a]&=val;
        andR[a]&=andR[b];

    }
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        parent=new int[n];
        andR=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
            andR[i]=(1<<20)-1;
        }
        for(int i=0;i<edges.length;i++){
            getUnion(edges[i][0],edges[i][1],edges[i][2]);
        }
        for(int i=0;i<n;i++){
            getP(i);
        }
        int sz=query.length;
        int res[]=new int[sz];
        for(int i=0;i<query.length;i++){
            int p1=parent[query[i][0]];
            int p2=parent[query[i][1]];
            // p1=getP(p1);
            // p2=getP(p2);
            if(p1!=p2){
                res[i]=-1;
            }else res[i]=andR[p1];
        }
        return res;

    }
}
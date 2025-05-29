class Solution {
    Map<Integer,ArrayList<Integer>> list1;
    Map<Integer,ArrayList<Integer>> list2;
    int dp[][];
    int dist[][];
    void doit(int i,int p,Map<Integer,ArrayList<Integer>> adj,int [][] arr){
        
        for(var x:adj.get(i)){
            if(x==p)continue;
            doit(x,i,adj,arr);
            arr[i][0]+=arr[x][1];
            arr[i][1]+=arr[x][0];
        }
        arr[i][0]+=1;

    }
    void fromP(int i,int p,Map<Integer,ArrayList<Integer>> adj,int [][] arr){
        if(p!=-1){
            arr[i][1]+=(arr[p][0]-arr[i][1]);
            arr[i][0]+=(arr[p][1]-arr[i][0]);
        }
        for(var x:adj.get(i)){
            if(x==p)continue;
            fromP(x,i,adj,arr);
        }
    }
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        // sum 
        int n=edges1.length;
        int m=edges2.length;
        list1=new HashMap<>();
        list2=new HashMap<>();
        for(int [] edge:edges1){
            int u=edge[0];
            int v=edge[1];
            list1.putIfAbsent(u,new ArrayList<>());
            list1.putIfAbsent(v,new ArrayList<>());
            list1.get(u).add(v);
            list1.get(v).add(u);
        }
        for(int [] edge:edges2){
            int u=edge[0];
            int v=edge[1];
            list2.putIfAbsent(u,new ArrayList<>());
            list2.putIfAbsent(v,new ArrayList<>());
            list2.get(u).add(v);
            list2.get(v).add(u);  
        }
        dp=new int[n+5][2];
        dist=new int[m+5][2];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],0);
        }

        for(int i=0;i<=m;i++){
            Arrays.fill(dist[i],0);
        }

        doit(0,-1,list1,dp);
        doit(0,-1,list2,dist);
        fromP(0,-1,list1,dp);
        fromP(0,-1,list2,dist);
        int cnt=0;
        for(int i=0;i<=m;i++){
            cnt=Math.max(cnt,dist[i][1]);
        }
        int [] res=new int[n+1];
        for(int i=0;i<=n;i++){
                res[i]=dp[i][0]+cnt;
        }
        return res;
    }
}
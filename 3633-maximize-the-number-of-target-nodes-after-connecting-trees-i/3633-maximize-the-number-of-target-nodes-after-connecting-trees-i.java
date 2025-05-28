class Solution {
    Map<Integer,ArrayList<Integer>> ort;
    Map<Integer,ArrayList<Integer>> actionTree;
    int cntSolve(int i,int p,int len){
        if(len<0) return 0;
        int cnt=0;
        for(var x:actionTree.get(i)){
            if(x==p)continue;
            cnt+=cntSolve(x,i,len-1);
        }
        return cnt+1;
    }
    int solve(int i,int p,int len){
        if(len<0) return 0;
        int cnt=0;
        for(var x:ort.get(i)){
            if(x==p)continue;
            cnt+=solve(x,i,len-1);
        }
        return cnt+1;
    }
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        ort=new HashMap<>();
        actionTree=new HashMap<>();
        for(int [] edge:edges1){
            int src=edge[0];
            int dest=edge[1];    
            ort.putIfAbsent(src, new ArrayList<>());
            ort.putIfAbsent(dest, new ArrayList<>());
            ort.get(src).add(dest);
            ort.get(dest).add(src);
        }
        for(int [] edge:edges2){
            int src=edge[0];
            int dest=edge[1];    
            actionTree.putIfAbsent(src, new ArrayList<>());
            actionTree.putIfAbsent(dest, new ArrayList<>());
            actionTree.get(src).add(dest);
            actionTree.get(dest).add(src);
        }
        int ans=0;
        int m=edges2.length;
        for(int i=0;i<=m;i++){
            int cnt=cntSolve(i,-1,k-1);
            ans=Math.max(ans,cnt);
        }
        int n=edges1.length;
        int [] res=new int[n+1];
        for(int i=0;i<=n;i++){
            res[i]=ans+solve(i,-1,k);
        }
        // res[0]=ans;
        return res;
    }
}
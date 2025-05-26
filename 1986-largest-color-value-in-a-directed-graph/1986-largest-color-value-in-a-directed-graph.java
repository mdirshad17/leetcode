class Solution {
    private Map<Integer, List<Integer>> adjList = new HashMap<>();
    int vis[];
    int dp[][];
    String COLOR;
    int st[];
    boolean cycle(int u){
        vis[u]=1;
        st[u]=1;
        // System.out
         if(adjList.get(u) != null && adjList.get(u).size()!=0){
        for(var x:adjList.get(u)){
           if(vis[x]==1 && st[x]==1){
            return true;
           }
           if(vis[x]==0){
           if(cycle(x)){
            return true;
           }}
        }
        }
       st[u]=0;
      return false;
    }
    void solve(int u){
        if(vis[u]==1) return;
         vis[u]=1;
        if( adjList.get(u) != null && adjList.get(u).size()!=0){
        for(var x:adjList.get(u)){
           if(vis[x]==0){ 
            solve(x);
            }
            for(int i=0;i<26;i++){
                dp[u][i]=Math.max(dp[u][i],dp[x][i]);
            }
        }
        }
        int cv=(int)(COLOR.charAt(u)-'a');
        dp[u][cv]+=1;
    }
    public int largestPathValue(String colors, int[][] edges) {
        COLOR=colors;
      for(int [] arr:edges){
        int src=arr[0];
        int dest=arr[1];
        adjList.putIfAbsent(src, new ArrayList<>());
        adjList.putIfAbsent(dest, new ArrayList<>());
        adjList.get(src).add(dest);
      }
      int n=colors.length();
      vis=new int[n+5];
      st=new int[n+5];
      dp=new int[n+5][27];
      for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(cycle(i)){
                return -1;
            }
        }
      }
      Arrays.fill(vis,0);
      for(int i=0;i<n;i++){
        if(vis[i]==0){
            solve(i);
        }
      }
      int ans=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<27;j++){
            ans=Math.max(dp[i][j],ans);
        }
      }
      return ans;  
    }

}
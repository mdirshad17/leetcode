class Solution {
    Map<Integer,List<Integer> > adj;
    int vis[];
    int par[];
    int dfs(int i,int j){
        par[i]=j;
        int ans=i;
        if(adj.containsKey(i) && adj.get(i).size()>=1){
            for(var x:adj.get(i)){
                if(par[x]!=-1)continue;
                ans=Math.min(dfs(x,j),ans);
            }
        }
        return vis[i]=ans;
    }
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        int n=s1.length();
        adj=new HashMap<>();
        for(int i=0;i<n;i++){
            int u=(int)(s1.charAt(i)-'a');
            int v=(int)(s2.charAt(i)-'a');
            if(u==v)continue;
            adj.putIfAbsent(u,new ArrayList<>());
            adj.putIfAbsent(v,new ArrayList<>());
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        vis=new int[26];
        par=new int[26];
        Arrays.fill(par,-1);
        for(int i=0;i<26;i++){
                if(par[i]==-1){
                   dfs(i,i);
                }
        }
        StringBuilder sbr=new StringBuilder();
        for(int i=0;i<baseStr.length();i++){
            int val=(int)(baseStr.charAt(i)-'a');
            int getP=par[val];
            int getVal=vis[getP];
            sbr.append((char)(getP+'a'));
        }
        return sbr.toString();
    }
}
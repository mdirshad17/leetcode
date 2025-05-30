class Solution {
    Map<Integer,ArrayList<Integer>> mp;
    int [] getDist(int n,int sn){
        int vis[]=new int[n];
        int dist[]=new int [n];
        for(int i=0;i<n;i++){
            dist[i]=100000000;
        }
        Queue<Integer> q=new LinkedList<>();
        q.add(sn);
        int lv=0;
        while(!q.isEmpty()){
            int ns=q.size();
            while(ns!=0){
                ns--;
               Integer node=q.poll(); 
               dist[node]=lv;
               vis[node]=1;
            //    System.out.println(lv+" "+node);
               for(var x:mp.get(node)){
                   if(vis[x]==0){
                    q.add(x);
                    vis[x]=1;
                   }
               }
            }
            lv++;
        }
        // for(int i=0;i<n;i++){
        //     System.out.print(dist[i]+" ");
        // }
        // System.out.println();
        return dist;

    }
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        mp=new HashMap<>();
        int n=edges.length;
        for(int i=0;i<n;i++){
            int u=i;
            int v=edges[i];
            mp.putIfAbsent(u,new ArrayList<>());
            if(v!=-1){
               mp.get(u).add(v);
            }
        }

        int [] dist=getDist(n,node1);
        int [] dist1=getDist(n,node2);

        // for(int i=0;i<n;i++){
        //     System.out.println(dist[i]+" "+i);
        //     // System.out.println(dist[i]+" "+dist1[i]);
        // }    
        int ans=Integer.MAX_VALUE;
        int noderes=-1;
        for(int i=0;i<n;i++){
            int disth=Math.max(dist[i],dist1[i]);
            if(disth<ans && disth<1000000){
                ans=disth;
                noderes=i;
            }

        }
        return noderes;
    }
}
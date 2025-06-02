class Solution {
    Map<Integer,Integer> mp;
    int solve(int n){
        if(n<=1) return n;
        if(mp.containsKey(n)) return mp.get(n);
        int ans=Integer.MAX_VALUE;
        for(int i=0;i<=2;i++){
            int op=i+1;
            int num=n-i;
            if((num%2)==0){
                ans=Math.min(ans,op+solve(num/2));
            }
            if((num%3)==0){
                ans=Math.min(ans,op+solve(num/3));
            }
        }
        mp.put(n,ans); 
        return ans;

        // return ans;
    }
    public int minDays(int n) {
        mp=new HashMap<>();
        return solve(n);
    }
}
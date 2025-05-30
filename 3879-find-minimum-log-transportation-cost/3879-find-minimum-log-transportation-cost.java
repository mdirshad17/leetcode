class Solution {
    public long minCuttingCost(int n, int m, int k) {
        if(n<=k && m<=k) return 0;
        long ans=0;
        while(n>k){
            ans+=(long)(n-k)*(long)k;
            n-=k;
        }
        while(m>k){
            ans+=(long)(m-k)*(long)k;
            m-=k;
        }
        return ans;
    }
}
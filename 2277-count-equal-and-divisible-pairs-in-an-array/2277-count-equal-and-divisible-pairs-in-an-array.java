class Solution {
    int gcd(int a,int b){
        if(a<b){
         int temp=b;
         b=a;
         a=temp;
        }
        if(b==0) return a;
        return gcd(b,a%b);
    }
    public int countPairs(int[] nums, int k) {
        int cnt=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            int l=gcd(i,k);
            int mul=k/l;
            for(int j=mul;j<n;j+=mul){
                if(j<=i)continue;
                cnt+=(nums[i]==nums[j])?1:0;
            }
        }
        return cnt;
    }
}
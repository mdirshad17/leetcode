class Solution {
    public int minimumRecolors(String blocks, int k) {
        
        int n=blocks.length();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=((blocks.charAt(i)=='B')?1:0);

        }
        int ans=k-sum;
        for(int i=k;i<n;i++){
            sum+=((blocks.charAt(i)=='B')?1:0);
            sum-=((blocks.charAt(i-k)=='B')?1:0);
            ans=Math.min(ans,k-sum);
        }
        return ans;
    }
}
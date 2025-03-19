class Solution {
    int BIT[];
    int N;
    void add(int x, int val) {
        while (x < N){
        BIT[x] ^= val;
        x += x & -x;
        }
        }
    int sum(int x) {return x!=0 ? BIT[x] ^ sum(x - (x & -x)) : 0;}
    public int minKBitFlips(int[] nums, int k) {
        int n=nums.length;
        BIT=new int[n+10];
        N=n+10;
        int ans=0;
        for(int i=0;i<n;i++){
            int idx=i+1;
            int currVal=nums[i]^sum(idx);
            // System.out.println(currVal);
            if(currVal==0 && i+k<=n){
                ans++;
                add(idx,1);
                add(idx+k,1);
            }
        }
        for(int i=0;i<n;i++){
            nums[i]^=sum(i+1);
            // System.out.println(nums[i]+" "+sum(i+1));
            if(nums[i]==0) return -1;
        }
        return ans;
    }
}
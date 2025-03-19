class Solution {
    public int minOperations(int[] nums) {
        int ans=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==0 && i+2<n){
                for(int j=i;j<=i+2;j++){
                    nums[j]^=1;
                }
                ans++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) return -1;
        }
        return ans;
    }
}
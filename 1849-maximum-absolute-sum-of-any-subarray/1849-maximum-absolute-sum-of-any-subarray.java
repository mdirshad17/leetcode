class Solution {
    // int solve(in)
    public int maxAbsoluteSum(int[] nums) {
        // return solve(nums);
        int csum=nums[0];
        int csum1=-1*nums[0];
        int n=nums.length;
        int ans=Math.max(csum,csum1);
        for(int i=1;i<n;i++){
            csum=Math.max(nums[i],csum+nums[i]);
            csum1=Math.max(-1*nums[i],csum1-nums[i]);
            ans=Math.max(ans,csum);
            ans=Math.max(ans,csum1);
        }
        return ans;
    }
}
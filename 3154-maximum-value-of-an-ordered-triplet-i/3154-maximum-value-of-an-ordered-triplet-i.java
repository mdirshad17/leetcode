class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans=0;
        int maxVal=nums[0];
        int minVal=nums[1];
        int n=nums.length;
        int diff[]=new int[n];
        for(int i=1;i<n;i++){
            diff[i]=Math.max(0,maxVal-nums[i]);
            diff[i]=Math.max(diff[i],diff[i-1]);
            maxVal=Math.max(maxVal,nums[i]); 
        }
        for(int i=2;i<n;i++){
            long res=diff[i-1]*(long)nums[i];
            ans=Math.max(res,ans);
        }
        return ans;
    }
}
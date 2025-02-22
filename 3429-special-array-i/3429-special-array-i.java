class Solution {
    public boolean isArraySpecial(int[] nums) {
        int n=nums.length;
        for(int i=1;i<n;i++){
            int diff=nums[i]+nums[i-1];
            if((diff%2)==0) return false;
        }
        return true;
    }
}
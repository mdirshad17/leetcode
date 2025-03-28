class Solution {
    public int jump(int[] nums) {
        int n=nums.length;
        if(n==1) return 0;
        int jumps=1;
        int currJump=nums[0];
        int maxJump=nums[0];
        for(int i=1;i<n;i++){
            maxJump=Math.max(maxJump,i+nums[i]);
            if(currJump<i) return -1;
            if(i==n-1) return jumps;
            if(currJump==i){
                currJump=maxJump;
                jumps++;
            }
            
        }
        return -1;   
    }
}
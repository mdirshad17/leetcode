class Solution {
    public boolean check(int[] nums) {
        int n=nums.length;
        int cnt=0;
        for(int i=1;i<2*n;i++){
            int pr=((i-1)%n+n)%n;
            int ni=(i%n);
            if(nums[ni]<nums[pr]){
                cnt++;
            }
        }
        return cnt<=2;
    }
}
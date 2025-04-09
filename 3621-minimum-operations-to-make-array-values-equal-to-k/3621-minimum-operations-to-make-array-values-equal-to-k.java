class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        if(nums[0]<k) return -1;
        Set<Integer> st=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            st.add(nums[i]);
        }
        int minus=nums[0]==k?1:0;
        return st.size()-minus;
    }
}
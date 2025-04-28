class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int n=nums.length;
        Map<Integer,Integer> mp=new HashMap<>();
        Set<Integer> st=new HashSet<>();
        for(int i=0;i<n;i++){
            st.add(nums[i]);
        }
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.containsKey(nums[i])){
                mp.put(nums[i],mp.get(nums[i])+1);
            }else mp.put(nums[i],1);

            while(mp.containsKey(nums[j]) && mp.get(nums[j])>1){
                mp.put(nums[j],mp.get(nums[j])-1);
                if(mp.get(nums[j])==0){
                    mp.remove(nums[j]);
                }
                j++;
            }

            if(mp.size()==st.size()){
                System.out.println(i+" "+j);
                ans+=(j+1);
            }
        }
        return ans;
    }
}
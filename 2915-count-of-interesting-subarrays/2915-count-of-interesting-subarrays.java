class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        long ans=0;
        int n=nums.size();
        Map<Integer,Integer> mp=new HashMap<>();
        int sum=0;
        mp.put(0,1);
        for(int i=0;i<n;i++){
            int numb=nums.get(i);
            numb%=modulo;
            int val=(numb==k)?1:0;
            sum+=val;
            sum=sum%modulo;
            int search=(((sum-k)%modulo)+modulo)%modulo;
            // System.out.println(sum+" "+search);
            if(mp.containsKey(search)){
                // cout<<search<<" "<<mp.get(search)<<"\n";
                // System.out.println(search+" "+mp.get(search)+" ");
                ans+=(long)mp.get(search);
            }

            if(mp.containsKey(sum)){
                mp.put(sum,mp.get(sum)+1);
            }else mp.put(sum,1);    
        }
        return ans;
    }
}
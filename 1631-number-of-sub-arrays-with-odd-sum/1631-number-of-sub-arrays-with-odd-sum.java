class Solution {
    public int numOfSubarrays(int[] arr) {
      HashMap<Integer,Integer> mp=new HashMap<>();
      mp.put(0,1);
      int sum=0;
      int ans=0;
      for(int i=0;i<arr.length;i++){
        int val=((arr[i]%2)+2)%2;
        sum+=val;
        sum=sum%2;
        if(mp.containsKey(1-sum)){
            ans+=mp.get(1-sum);
        }

        if(mp.containsKey(sum)){
            mp.put(sum,mp.get(sum)+1);
        }else mp.put(sum,1);
      }
      return ans;   
    }
}
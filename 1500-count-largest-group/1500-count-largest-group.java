class Solution {
    public int countLargestGroup(int n) {
        Map<Integer,Integer> mp=new HashMap<>();
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=i;
            int sum=0;
            while(num!=0){
                sum+=(num%10);
                num=num/10;
            }
            if(mp.containsKey(sum)){
                mp.put(sum,mp.get(sum)+1);
            }else mp.put(sum,1);
            // System.out.println(sum);

            ans=Math.max(ans,mp.get(sum));
        }
        int ansCount=0;
        for (Map.Entry<Integer,Integer> mapElement : mp.entrySet()) {
            int value = (mapElement.getValue());
            if(value==ans){
                ansCount++;
            }
        }
        return ansCount;
    }
}
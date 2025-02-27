class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n=arr.length;
        // int res[]=new int[n];
        HashMap<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<n;i++){
            mp.put(arr[i],1);
        }
        int res=0;
        for(int i=n-1;i>=0;i--){
            int maxH=1;
            int ans=0;
           for(int j=i+1;j<n;j++){
            int prev=arr[i];
            int next=arr[j];
            int len=2;
            while(mp.containsKey(prev+next)){
                // res=max()
                len++;
                res=Math.max(res,len);
                int sum=prev+next;
                prev=next;
                next=sum;
            }
           }
        
       
        }
        return res;
    }
}
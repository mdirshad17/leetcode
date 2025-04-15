class Solution {
int N;    
long BIT[];
void add(int x, long val) {while (x < N){
BIT[x] += val; x += x & -x;}
}
long sum(int x) {return x>0 ? BIT[x] + sum(x - (x & -x)) : 0;}

    public long goodTriplets(int[] nums1, int[] nums2) {
        Map<Integer,Integer> mp=new HashMap<>();
        int n=nums1.length;
        for(int i=0;i<n;i++){
            mp.put(nums2[i],i);
        }
        int res[]=new int[n];
        for(int i=0;i<n;i++){
            res[i]=mp.get(nums1[i]);
        }
        long count[]=new long[n];
        N=n+5;
        BIT=new long[N];
        long ans=0;
        // lo
        for(int i=0;i<n;i++){
            // 
            int curN=res[i]+1;
            long cnt=sum(curN-1);
            count[i]=cnt;
            add(curN,1);
        }
        for(int i=0;i<N;i++){
            BIT[i]=0;
        }
        
        for(int i=0;i<n;i++){
            int curN=res[i]+1;
            ans+=sum(curN-1);
            add(curN,count[i]);
        }
        return ans;



    }
}
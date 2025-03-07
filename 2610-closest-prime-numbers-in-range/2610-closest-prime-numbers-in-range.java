class Solution {
    int primes[];
     void soe(){
        int N=1000005;
        primes=new int[N];
        primes[1]=1;

        for(int i=2;i<N;i++){
            if(primes[i]==1)continue;
            for(int j=2*i;j<N;j+=i){
                primes[j]=1;
            }
        }
     }
    public int[] closestPrimes(int left, int right) {
        soe();
        int prev=-1;
        int diff=Integer.MAX_VALUE;
        int firstNum=-1;
        for(int i=left;i<=right;i++){
             if(primes[i]==0){
                // cout<<i<<" \n";
                // System.out.println(i)
                if(prev==-1){
                    prev=i;
                }else{
                    int diffh=i-prev;
                    if(diffh<diff){
                        diff=diffh;
                        firstNum=prev;
                    }
                    prev=i;
                }
             }
        }
        int res[]=new int[2];
        // for(i)
        res[0]=-1;
        res[1]=-1;
        if(firstNum!=-1) {
            res[0]=firstNum;
            res[1]=firstNum+diff;

        }
        return res;
    }
}
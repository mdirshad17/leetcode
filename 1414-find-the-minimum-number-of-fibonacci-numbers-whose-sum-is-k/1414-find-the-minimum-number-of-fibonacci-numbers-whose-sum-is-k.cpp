class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        // greedy works here
        int fib[100];
        fib[0]=1;
        fib[1]=1;
        int idx=0;
        for(int i=2;i<100;i++){
            fib[i]=fib[i-1]+fib[i-2];
            if(fib[i]>=k){
                idx=i;
                break;
            }
        }
        int cnt=0;
        while(k!=0){
            cnt+=k/fib[idx];
            k=k%fib[idx];
            idx--;
        }
        return cnt;
        
        
    }
};
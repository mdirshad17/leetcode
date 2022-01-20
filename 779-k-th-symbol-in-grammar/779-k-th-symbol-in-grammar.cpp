class Solution {
public:
    int solve(int n,int k,int f){
        if(n==0){
            return f%2;
        }
        int total=(1<<n);
        int ht=total/2;
        // cout<<ht<<" "<<k<<endl;
        if(k>ht){
            return solve(n-1,k-ht,(f^1));
        }else{
            return solve(n-1,k,f);
        }
    }
    int kthGrammar(int n, int k) {
        return solve(n-1,k,0);
    }
};
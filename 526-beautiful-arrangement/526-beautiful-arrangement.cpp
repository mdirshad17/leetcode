class Solution {
public:
    int used[16];
    int solve(int s,int n){
        if(s>n){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!used[i] && (((i%s)==0) || ((s%i)==0))){
                used[i]=1;
                ans+=solve(s+1,n);
                used[i]=0;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        return solve(1,n);
    }
};
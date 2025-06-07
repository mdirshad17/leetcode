class Solution {
    int dp[];
    int solve(int n){
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=1;i<n;i++){
            if((n%i)==0){
                if(solve(n-i)==0){
                    return dp[n]=1;
                }
            }
        }
        return dp[n]=0;
    }
    public boolean divisorGame(int n) {
        if(n==1) return false;
        dp=new int[n+5];
        Arrays.fill(dp,-1);
        if(solve(n)==1) return true;
        return false;
        
    }
}
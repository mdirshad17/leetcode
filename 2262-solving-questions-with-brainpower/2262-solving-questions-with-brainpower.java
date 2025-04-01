class Solution {
    long dp[];
    long solve(int i,int n,int[][] questions){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long op1=solve(i+1,n,questions);
        long op2=questions[i][0]+solve(i+questions[i][1]+1,n,questions);
        return dp[i]=Math.max(op1,op2);
    }
    public long mostPoints(int[][] questions) {
        int n=questions.length;
        dp=new long[n];
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        return solve(0,n,questions);
    }
}
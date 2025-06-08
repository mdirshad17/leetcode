class Solution {
    int dp[][];
    int solve(int i,int n,int[] satisfaction,int time){
        if(i>=n) return 0;
        if(dp[i][time]!=Integer.MIN_VALUE) return dp[i][time];
        int op1=solve(i+1,n,satisfaction,time);
        int op2=(satisfaction[i]*time)+solve(i+1,n,satisfaction,time+1);
        return dp[i][time]= Math.max(op1,op2);
    }
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        dp=new int[505][505];
        for(int i=0;i<505;i++){
            for(int j=0;j<505;j++){
                dp[i][j]=Integer.MIN_VALUE;
            }
        }
        return solve(0,satisfaction.length,satisfaction,1);
        // return 0;
    }
}
class Solution {
    int solve(int i,int n,int []coins,int amount,int dp[][]){
           if(amount==0)return 0;
            if(i>=n||amount<0){
                return Integer.MAX_VALUE/10;
            }
            if(dp[i][amount]!=-1)return dp[i][amount];
            int op1=1+solve(i+1,n,coins,amount-coins[i],dp);
            int op2=solve(i+1,n,coins,amount,dp);
            return dp[i][amount]=Math.min(op1,op2);
    }
    public boolean canPartition(int[] nums) {
        int sum=0;
        for(int x:nums)sum+=x;
        if((sum&1)==1)return false;
        sum=sum/2;
        int n=nums.length;
          int [][]dp= new int[n+5][sum+5];
          for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
          }
          int ans=solve(0,n,nums,sum,dp);
          return ans>=Integer.MAX_VALUE/10?false:true;

        // return sum==0;
    }
}
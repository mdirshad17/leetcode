class Solution {
public:
    int dp[30][30];
    int solve(int l,int r,vector<int> & nums){
        if(l>r)return 0;
        if(l==r)return nums[l];
        if(dp[l][r]!=-1)return dp[l][r];
        int op1=nums[l]-solve(l+1,r,nums);
        int op2=nums[r]-solve(l,r-1,nums);
        return dp[l][r]=max(op1,op2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int s=solve(0,n-1,nums);
        return (s>=0);
    }
};
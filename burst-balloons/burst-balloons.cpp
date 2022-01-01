class Solution {
public:
    int dp[520][520];
    int solve(int l,int r,vector<int> & nums){
        if(l>r)return 0;
        if(l==r)return nums[l-1]*nums[l]*nums[l+1];
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        for(int i=l;i<=r;i++){
            int coins=nums[l-1]*nums[i]*nums[r+1];
            int op1=solve(l,i-1,nums);
            int op2=solve(i+1,r,nums);
            ans=max(ans,op1+op2+coins);
        }
        return dp[l][r]=ans;

    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        int f=solve(1,n,nums);
        return f;
        
    }
};
class Solution {
public:
    double dp[105][105];
    double solve(int s,int n,vector<int> & nums,int k){
        if(s>=n){
            if(k==0)return 0;
            return INT_MIN/10;
        }
        if(k<=0)return INT_MIN/10;
        if(dp[s][k]!=INT_MIN)return dp[s][k];
        double ans=0;
        double sum=0;
        int len=0;
        for(int i=s;i<n;i++){
            sum+=nums[i];
            len++;
            double res=(1.0*sum/len)+solve(i+1,n,nums,k-1);
            ans=max(ans,res);
        }
        return dp[s][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                dp[i][j]=INT_MIN;
            }
        }
        int n=nums.size();
        return solve(0,n,nums,k);
    }
};
class Solution
{
    public:
    
    double dp[105][105];
    double solve(int i, int n, int k, vector<int> &nums)
    {
        if (k < 0) return INT_MIN / 10;
        if (i >= n) return 0;
        if(dp[i][k]!=-1.00)return dp[i][k];
        double globalans = INT_MIN;
        double subsum = 0;
        for (int j = i; j < n; j++)
        {
            subsum += nums[j];
            double avg = 1.0 *subsum / (j - i + 1);
            double localans = avg + solve(j + 1, n, k - 1, nums);
            globalans = max(globalans, localans);
        }
        return dp[i][k]=globalans;
    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        for(int i=0;i<n+5;i++){
            for(int j=0;j<k+5;j++){
                dp[i][j]=-1.00;
            }
        }
        
        double ans = solve(0, n, k, nums);
        return ans;
    }
};
class Solution
{
    public:
        bool checkPossibility(vector<int> &nums)
        {
            int n = nums.size();
            int dp[n];
            memset(dp, 0, sizeof(dp));
            int dpr[n];
            memset(dpr, 0, sizeof(dpr));
            for (int i = 0; i < n; i++)
            {
                dp[i] = 1;
                if (i != 0 && nums[i] >= nums[i - 1])
                {
                    dp[i] += (dp[i - 1]);
                }
            }
            if (dp[n - 1] == n) return 1;
            for (int i = n - 1; i >= 0; i--)
            {
                dpr[i] = 1;
                if (i != n - 1 && nums[i] <= nums[i + 1])
                {
                    dpr[i] += (dpr[i + 1]);
                }
            }
            // for(int i=0;i<n;i++){
            //     cout<<dp[i]<<" ";
            // }cout<<endl;
            // for(int i=0;i<n;i++){
            //     cout<<dpr[i]<<" ";
            // }cout<<endl;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int left = (i - 1 >= 0 ? nums[i - 1] : INT_MIN);
                int right = (i + 1 < n ? nums[i + 1] : INT_MAX);
                if (left <= right)
                {
                    int cntl = (i - 1 >= 0 ? dp[i - 1] : 0);
                    int cntr = (i + 1 < n ? dpr[i + 1] : 0);
                    // cout<<cntl<<" "<<cntr<<" "<<endl;
                    if ((cntl + cntr + 1) >= n) return 1;
                }
            }
            return 0;
        }
};
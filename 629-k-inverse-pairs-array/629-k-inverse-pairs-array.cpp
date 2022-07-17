class Solution
{
    public:
    #define ll long long 
    #define M 1000000007
    ll dp[1005][1005];
                 
        int kInversePairs(int n, int k)
        {
            dp[0][0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                dp[i][0] = 1;
                for (int j = 1; j <= k; ++j)
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % M;
                    if (j - i >= 0)
                    {
                        dp[i][j] = ((dp[i][j] - dp[i - 1][j - i])%M + M) % M;
                    }
                }
            }
            return dp[n][k];
        }
};
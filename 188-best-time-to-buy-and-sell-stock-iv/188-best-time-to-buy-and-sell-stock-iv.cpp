class Solution
{
    public:
        int dp[1005][105][2];
    int solve(int s, int n, vector<int> &v, int k, int buy)
    {
        if (k < 0) return INT_MIN / 100;
        if (s >= n) return 0;
        if (dp[s][k][buy] != -1) return dp[s][k][buy];
        int op1 = solve(s + 1, n, v, k, buy);
        int op2 = 0;
        if (buy == 1)
        {
            op2 = -v[s] + solve(s + 1, n, v, k, 0);
        }
        else
        {
            op2 = v[s] + solve(s + 1, n, v, k - 1, 1);
        }
        return dp[s][k][buy] = max(op1, op2);
    }
    int maxProfit(int k, vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, prices.size(), prices, k, 1);
    }
};
class Solution
{
    public:
#define ll long long
#define M 1000000007
    int dx[4] = { -1,
        1,
        0,
        0
    };
    int dy[4] = { 0,
        0,
        -1,
        1
    };
    ll dp[55][55][55];
    ll solve(int r, int c, int n, int m, int Moves)
    {
        if (Moves < 0) return 0;
        if (r < 0 || r >= n || c < 0 || c >= m) return 1;
        if (dp[r][c][Moves] != -1) return dp[r][c][Moves];
        ll ans = 0;
        for (int i = 0; i < 4; i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];
            ans += solve(x, y, n, m, Moves - 1);
            ans = ans % M;
        }
        return dp[r][c][Moves] = ans % M;
    }
    int findPaths(int m, int n, int maxMove, int sr, int sc)
    {
        swap(n, m);
        memset(dp, -1, sizeof(dp));
        return solve(sr, sc, n, m, maxMove);
    }
};
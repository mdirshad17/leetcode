class Solution
{
    public:
        int dp[205][205];
    int n, m;
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
    #define ll long long 
    int solve(int r, int c, vector<vector<int>> &v, ll p)
    {
        if (r < 0 || c < 0 || r >= n || c >= m || p <= v[r][c])
        {
            return 0;
        }
        if (dp[r][c] != -1) return dp[r][c];
        int l = 0;
        for (int i = 0; i < 4; i++)
        {
            int X = r + dx[i];
            int Y = c + dy[i];
            l = max(l, solve(X, Y, v, v[r][c]));
        }
        return dp[r][c] = (l + 1);
    }
    int longestIncreasingPath(vector<vector < int>> &matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int l = solve(i, j, matrix, LONG_MAX);
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
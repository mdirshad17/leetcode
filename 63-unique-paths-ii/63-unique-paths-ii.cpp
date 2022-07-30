class Solution
{
    public:
        int dp[105][105];
    int solve(int r, int c, int m, int n, vector<vector < int>> &G)
    {
        if (r >= m || c >= n) return 0;
        
        // if obstacle
        if (G[r][c] == 1) return 0;
        if (r == m - 1 && c == n - 1) return 1;
  

        if (dp[r][c] != -1) return dp[r][c];
        int op1 = solve(r, c + 1, m, n,G);
        int op2 = solve(r + 1, c, m, n,G);
        return dp[r][c] = op1 + op2;
    }
    int uniquePathsWithObstacles(vector<vector < int>> & G) {
        int m=G.size(); // number of rows
        int n=G[0].size() ;// number of cols
        memset(dp,-1,sizeof(dp));
        int f=solve(0,0,m,n,G);
        return f;
    }
};
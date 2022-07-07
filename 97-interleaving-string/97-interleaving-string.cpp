class Solution
{
    public:
        int dp[102][102];
        int solve(int s1, int s2, int n, int m, int s3, string &s, string &p, string &t)
        {
            s3 = s1 + s2;
            if ((s3 >= t.size()) && (s1 >= n) && (s2 >= m)) return 1;
            if (s1 >= n && s2 >= m) return 0;
            if(dp[s1][s2]!=-1)return dp[s1][s2];
            int ans = 0;
            if (s1 < n && s[s1] == t[s3])
            {
                ans = ans | solve(s1 + 1, s2, n, m, s3, s, p, t);
            }
            if (s2 < m && p[s2] == t[s3])
            {
                ans = ans | solve(s1, s2 + 1, n, m, s3, s, p, t);
            }
            return  dp[s1][s2]=ans;
        }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();
        int N = s3.size();
        memset(dp,-1,sizeof(dp));
        if (((n + m) != N)) return 0;
        // cout
        return solve(0, 0, n, m, 0, s1, s2, s3);
    }
};
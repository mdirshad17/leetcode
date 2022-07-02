class Solution
{
    public:
        int n, m;
    int dp[30][35];
    int solve(int s1, string &s, int s2, string &p)
    {
        if (s1 >= n && s2 >= m) return 1;
        // if (s1 >= n)
        // {
        //     if (p[s2] == '*') return dp[s1][s2]=solve(s1, s, s2 + 1, p);
        //     return dp[s1][s2]=0;
        // }
        if (s2 >= m) return 0;
        int ans = 0;
        if(dp[s1][s2]!=-1)return dp[s1][s2];
        if (isalpha(p[s2]))
        {
            if (s1<n && p[s2] == s[s1]) ans = ans | solve(s1 + 1, s, s2 + 1, p);
            if ((s2+1) < m && p[s2+1] == '*') ans = ans | solve(s1, s, s2 + 2, p);
        }
        else if (p[s2] == '.')
        {
            if(s1<n){
            ans = ans | solve(s1 + 1, s, s2 + 1, p);}
            if ((s2+1) < m && p[s2+1] == '*') ans = ans | solve(s1, s, s2 + 2, p);
        }
        else
        {
            ans = ans | solve(s1, s, s2 + 1, p);
            if (s1<n && (p[s2 - 1] == s[s1] || p[s2 - 1] == '.')) ans = ans | solve(s1 + 1, s, s2, p);
        }
        return dp[s1][s2]=ans;
    }
    bool isMatch(string s, string p)
    {
        memset(dp,-1,sizeof(dp));
        n = s.size();
        m = p.size();
        int f = solve(0, s, 0, p);
        return f;
    }
};
class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int n = s.size();
            int dp[n][n];
            memset(dp, 0, sizeof(dp));
            for (int g = 0; g < n; g++)
            {
                for (int i = 0, j = g; j < n; i++, j++)
                {
                    if (g == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else if (g == 1)
                    {
                        dp[i][j] = (s[i] == s[j]);
                    }
                    else
                    {
                        dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                    }
                }
            }
            int ans = 0;
            int si = -1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dp[i][j])
                    {
                        int len = j - i + 1;
                        if (ans < len)
                        {
                            ans = len;
                            si = i;
                        }
                    }
                }
            }
            return s.substr(si, ans);
        }
};
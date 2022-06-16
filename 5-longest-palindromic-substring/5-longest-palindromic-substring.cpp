class Solution
{
    public:
        string longestPalindrome(string s)
        {

            int n = s.size();
            
            vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
            // dp[i][j]=1 substring from i to j palindrome
            //    0 not palindrome 
            int ans = 0;
            int s1 = -1;
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
                        if (s[i] == s[j])
                        {
                            dp[i][j] = dp[i + 1][j - 1];
                        }
                    }
                    if (dp[i][j])
                    {
                        if (g + 1 > ans)
                        {
                            ans = g + 1;
                            s1 = i;
                        }
                    }
                }
            }
            return s.substr(s1, ans);
        }
};
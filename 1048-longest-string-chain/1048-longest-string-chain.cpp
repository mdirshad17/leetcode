class Solution
{
    public:
    int d[17][2];
        int check(int s1, int f, string &s, string &p)
        {
            int n = s.size();
            if (s1 >= n) return 1;
            if(d[s1][f]!=-1)return d[s1][f];
            int op1 = 0;
            if (f == 0) op1 = check(s1, 1, s, p);
            int op2 = 0;
            if (s[s1] == p[(s1 + f)]) op2 = check(s1 + 1, f, s, p);
            return d[s1][f]=(op1 | op2);
        }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b)
        {
            return (a.size() > b.size());
	});
        int dp[n + 5];
        memset(dp, 0, sizeof(dp));
        dp[n - 1] = 1;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = 1;
            int ns = words[i].size();
            int add = 0;
            for (int j = i + 1; j < n; j++)
            {
                int m = words[j].size();
                if(ns==m+2)break;
                if (ns==m + 1)
                {  
                    memset(d,-1,sizeof(d));
                    int f = check(0, 0, words[j], words[i]);
                    if (f)
                    {
                        add = max(add, dp[j]);
                    }
                }
            }
            // cout<<endl<<endl;
            dp[i] += add;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
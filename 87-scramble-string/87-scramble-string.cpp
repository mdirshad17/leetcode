class Solution
{
    public:
        int dp[32][32][32][32];
    int solve(int l, int r, int s, int e, string &p, string &q)
    {

       	// if(l>r)return 0; 
        if (l == r) return (p[l] == q[s]);

        int len1 = (r - l) + 1;
        int len2 = (e - s) + 1;

        if (len1 != len2) return 0;
        int si = s;
        int f = 1;
        for (int i = l; i <= r; i++)
        {
            if (q[si] != p[i])
            {
                f = 0;
                break;
            }
            si++;
        }
        if (f) return 1;
        int ans = 0;
       	if(dp[l][r][s][e]!=-1)return dp[l][r][s][e];
        for (int i = l; i < r; i++)
        {
            // int sub1 = l, i;
            // int sub2=i+1,r;
            int ls=(i-l+1);
            int ls1=(r-i);
            int op1=(solve(l,i,e-ls+1,e,p,q) && solve(i+1,r,s,s+ls1-1,p,q));
            
            int op2=(solve(l,i,s,s+ls-1,p,q) && solve(i+1,r,e-ls1+1,e,p,q));
            ans=(ans|op1|op2);
        }
        return dp[l][r][s][e] = ans;
    }
    bool isScramble(string s1, string s2)
    {

        memset(dp, -1, sizeof(dp));
        int n = s1.size();
        int m = s2.size();
        if (n != m) return 0;
        return solve(0, n - 1, 0, m - 1, s1, s2);
    }
};
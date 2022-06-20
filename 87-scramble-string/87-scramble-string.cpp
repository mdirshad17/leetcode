class Solution
{
    public:
        int dp[32][32][32];
    int solve(int l, int r, int s,string &p, string &q)
    {
        
       	// if(l>r)return 0; 
        if (l == r) return (p[l] == q[s]);
        
        int len = (r - l) + 1;
        int e=s+len-1;
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
       	if(dp[l][r][s]!=-1)return dp[l][r][s];
        for (int i = l; i < r; i++)
        {
            // int sub1 = l, i;
            // int sub2=i+1,r;
            int ls=(i-l+1);
            int ls1=(r-i);
            int op1=(solve(l,i,e-ls+1,p,q) && solve(i+1,r,s,p,q));
            
            int op2=(solve(l,i,s,p,q) && solve(i+1,r,e-ls1+1,p,q));
            ans=(ans|op1|op2);
        }
        return dp[l][r][s] = ans;
    }
    bool isScramble(string s1, string s2)
    {

        memset(dp, -1, sizeof(dp));
        int n = s1.size();
        int m = s2.size();
        if (n != m) return 0;
        return solve(0, n - 1, 0, s1, s2);
    }
};
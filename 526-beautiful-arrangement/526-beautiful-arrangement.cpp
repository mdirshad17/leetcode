class Solution
{
    public:
    int dp[1<<15];
    int cnt=0;
        int solve(int n, int mask)
        {

           	//... base case
            int i=__builtin_popcount(mask);
            if(i>=n){
                return 1;
            }
            if(dp[mask]!=-1)return dp[mask];    
           	// follow the constraint of the problem
           	// constraint to be a permutation
            cnt++;
            int ans = 0;
        
            for (int j = 1; j <= n; j++)
            {
                if ((mask &(1 << (j - 1))) != 0) continue;
                
                if ((j % (i + 1)) == 0 || ((i + 1) % j) == 0)
                {
                    ans += solve( n, (mask | (1 << (j - 1))));
                }
            }
            return dp[mask]=ans;
        }
    int countArrangement(int n)
    {
        memset(dp,-1,sizeof(dp));

        int ans = solve( n, 0);
        cout<<cnt<<endl;
        return ans;
    }
};
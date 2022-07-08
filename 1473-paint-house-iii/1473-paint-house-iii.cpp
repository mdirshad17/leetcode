class Solution
{
    public:
        int mn, nn;
    vector<vector < int>> C;
    vector<int> H;
    int dp[105][105][25];
    int solve(int s, int T, int cl)
    {
        if (T < 0) return INT_MAX / 10;
        if (s >= mn)
        {
            if (T == 0) return 0;
            return INT_MAX / 10;
        }
        if(dp[s][T][cl+1]!=-1)return dp[s][T][cl+1];
        int ans = INT_MAX / 10;
        if (H[s] != 0)
        {
            ans = solve(s + 1, (T - (cl != H[s])), H[s]);
        }
        else
        {
            for (int i = 0; i < nn; i++) {
                int l=C[s][i]+solve(s+1,T-(cl!=(i+1)),i+1);
                ans=min(ans,l);
            }
        }
        return dp[s][T][cl+1]=ans;
    }
    int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target)
    {
        mn = m;
        nn = n;
        C = cost;
        H = houses;
        memset(dp,-1,sizeof(dp));
        int f = solve(0, target, -1);
        if(f>=INT_MAX/10)f=-1;
        return f;
    }
};
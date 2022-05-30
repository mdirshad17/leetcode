class Solution
{
    public:
#define ll long long
#define M 1000000007
    int dp[45][1100];
    vector<int> adj[45];
    int bts = 0;
    int get_b(int n)
    {
        int cnt = 0;
        while (n)
        {
            cnt += (n & 1);
            n = n / 2;
        }
        return cnt;
    }
    ll solve(int s, int n, int mask)
    {

        int cnt = get_b(mask);
       	// cout<<cnt<<endl;
        if (cnt == bts)
        {
            return 1;
        }
        if (s >= n)
        {
            return 0;
        }
        if (dp[s][mask] != -1) return dp[s][mask];
        ll ans = solve(s + 1, n, mask);
        for (int x: adj[s])
        {
            if ((mask &(1 << x))) continue;
            ans += solve(s + 1, n, (mask | (1 << x)));
            ans = ans % M;
        }
        return dp[s][mask] = (ans % M);
    }
    int numberWays(vector<vector < int>> &hats)
    {

        memset(dp, -1, sizeof(dp));
        bts = hats.size();
        for (int i = 0; i < hats.size(); i++)
        {
            for (int j = 0; j < hats[i].size(); j++)
            {
                adj[hats[i][j]].push_back(i);
            }
        }
        ll ans = solve(1, 41, 0);
        ans = ans % M;
        return ans;
    }
};
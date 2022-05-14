class Solution
{
    public:
        int networkDelayTime(vector<vector < int>> &times, int n, int K)
        {
            K--;
            int wt[n][n];
            memset(wt, -1, sizeof(wt));
            for (auto x: times)
            {
                int u = x[0];
                int v = x[1];
                int t = x[2];
                u--;
                v--;
                wt[u][v] = t;
            }
            for (int i = 0; i < n; i++)
            {
                wt[i][i] = 0;
                for (int j = 0; j < n; j++)
                {
                    if (wt[i][j] == -1)
                    {
                        wt[i][j] = INT_MAX;
                    }
                }
            }
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (wt[i][k] == INT_MAX || wt[k][j] == INT_MAX) continue;
                        wt[i][j] = min(wt[i][k] + wt[k][j], wt[i][j]);
                    }
                }
            }
            int mt = *max_element(wt[K], wt[K] + n);
            if (mt == INT_MAX) return -1;
            return mt;
        }
};
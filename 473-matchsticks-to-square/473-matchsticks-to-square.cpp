class Solution
{
    public:
        int M;
    int S;
    vector<int> v;
    void generate(int s, int n, vector<int> &m, int req, int mask)
    {
        if (s >= n)
        {
            if (req == S)
            {
                v.push_back(mask);
            }
            return;
        }
        generate(s + 1, n, m, req, mask);
        generate(s + 1, n, m, req + m[s], (mask | 1 << s));
    }
   	// vector<int> dp[(1 << 15)][6];
    int solve(int s, int mask, int cnt)
    {
        if (cnt < 0) return 0;
        if (cnt == 0 && mask == M) return 1;

        if (s >= v.size() || mask == M) return 0;
       	// if (dp[mask][cnt][s] != -1) return dp[mask][cnt][s];
        int op1 = 0;
       	// cout<<mask<<endl;
        if ((mask &v[s]) == 0)
        {
            op1 = solve(s + 1, (mask | (v[s])), cnt - 1);
        }
        if (op1) return 1;
        int op2 = solve(s + 1, mask, cnt);
        return op2;
    }
    bool makesquare(vector<int> &m)
    {
        int sum = 0;
        int n = m.size();
        for (int i = 0; i < n; i++)
        {
            sum += m[i];
        }
        if (sum % 4) return 0;
        int req = sum / 4;
        S = req;
        M = (1 << n) - 1;
        generate(0, n, m, 0, 0);
        int l = v.size();
        // if (l <= 200)
        // {
        //     for (int i = 0; i < l; i++)
        //     {
        //         for (int j = i + 1; j < l; j++)
        //         {
        //             for (int k = j + 1; k < l; k++)
        //             {
        //                 for (int o = k + 1; o < l; o++)
        //                 {
        //                     if ((v[i] &v[j]) || v[i] &v[k] || v[i] &v[o] || v[j] &v[k] || v[j] &v[o] || v[k] &v[o]){
        //                         continue;
        //                     }
        //                     int mt=v[i]|v[j]|v[k]|v[o];
        //                     if(mt==M)return 1;
        //                 }
        //             }
        //         }
        //     }
        //     return 0;
        // }
       	// for (int i = 0; i < (1 << n); i++)
       	// {
       	//     for (int j = 0; j < 5; j++)
       	//     {
       	//         dp[i][j].clear();
       	//         dp[i][j].assign(v.size(), -1);
       	//     }
       	// }
       	// cout<<v.size()<<endl;
        int f = solve(0, 0, 4);
        return f;
    }
};
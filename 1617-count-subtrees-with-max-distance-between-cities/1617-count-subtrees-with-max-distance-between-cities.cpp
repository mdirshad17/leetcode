class Solution
{
    public:
        int a[16][16];
    int d[16][16];
    vector<int> adj[16];
    vector<int> get(int n)
    {
        int s = 0;
        vector<int> v;
        while (n)
        {
            if (n & 1)
            {
                v.push_back(s);
            }
            s++;
            n = n / 2;
        }
        return v;
    }
    void dfs(int s, int e, int mask, int p, int sp, int dist)
    {

        if (s == e)
        {
            int msk = (mask | (1 << e));
            a[sp][e] = msk;
            a[e][sp] = msk;
            d[sp][e] = dist;
            d[e][sp] = dist;
            return;
        }
        for (auto x: adj[s])
        {
            if (x == p) continue;

            dfs(x, e, (mask | (1 << s)), s,sp, (dist + 1));
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector < int>> &edges)
    {

        for (auto x: edges)
        {
            x[0]--;
            x[1]--;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if ((i != j) && (d[i][j] == 0))
                {
                    dfs(i, j, 0, -1, i, 0);
                }
            }
        }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout<<d[i][j]<<" ";
//             }cout<<endl;
//         }
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout<<a[i][j]<<" ";
//             }cout<<endl;
//         }
        vector<int> dx(n - 1, 0);
        for (int i = 1; i < (1 << n); i++)
        {
            vector<int> v = get(i);
            if (v.size() == 1) continue;
            
            // for(int x:v){
            //     cout<<x<<" ";
            // }cout<<endl;
            
            // return {};
            int dmax = 0;
            int f = 0;
            for (int j = 0; j < v.size(); j++)
            {
                for (int k = j + 1; k < v.size(); k++)
                {
                    int msk = a[v[j]][v[k]];
                    int dist = d[v[j]][v[k]];
                    
                    if ((msk & i) != msk)
                    {
                        f = 1;
                        break;
                    }
                    dmax = max(dmax, dist);
                }
            }
            if (f == 0)
            {
                dx[dmax - 1]++;
            }
        }
        return dx;
    }
};
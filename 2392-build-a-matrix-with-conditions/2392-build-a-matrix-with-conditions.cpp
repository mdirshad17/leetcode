class Solution
{
    public:
        int k;

    vector<int> PRO(vector<vector < int>> &v, int k)
    {
        int n = v.size();
        vector<int> adj[k + 1];
        queue<int> q;
        int ind[k + 1];
        memset(ind, 0, sizeof(ind));
        for (auto x: v)
        {
            adj[x[0]].push_back(x[1]);
            ind[x[1]]++;
        }
        for (int i = 1; i <= k; i++)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> order;
        while (q.size())
        {
            int d = q.front();
            q.pop();
            order.push_back(d);
            for (int x: adj[d])
            {
                ind[x]--;
                if (ind[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        if (order.size() != k) return {};
        return order;
    }
    vector<vector < int>> buildMatrix(int K, vector<vector < int>> &RC, vector< vector< int>> &CC)
    {
        k = K;
        vector<int> X=PRO(RC, k);
        vector<int> Y=PRO(CC, k);
        if(X.size()==0||Y.size()==0) return {};
        int XX[k+1];
        int YY[k+1];
        vector<vector<int> > RES(k,vector<int>(k,0));
        for(int i=0;i<X.size();i++){
            XX[X[i]]=i;
            YY[Y[i]]=i;
        }
        for(int i=1;i<=k;i++){
            RES[XX[i]][YY[i]]=i;
        }
        return RES;
        
    }
};
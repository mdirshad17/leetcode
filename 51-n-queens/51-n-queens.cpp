class Solution
{
    public:
        vector<vector < string>> ans;
    int col[10];
    int rc[20];
    unordered_map<int, int> lc;
    bool safe(int r, int c)
    {
        if (col[c] == 1) return 0;
        if (lc[r - c] == 1) return 0;
        if (rc[r + c] == 1) return 0;
        return 1;
    }
    void solve(int r, int n, vector<string> &v)
    {
        if (r >= n)
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (safe(r, i))
            {
                v[r][i] = 'Q';
                col[i] = 1;
                lc[r - i] = 1;
                rc[r + i] = 1;
                solve(r + 1, n, v);
                v[r][i] = '.';
                col[i] = 0;
                lc[r - i] = 0;
                rc[r + i] = 0;
            }
        }
    }
    vector<vector < string>> solveNQueens(int n)
    {
        string s;
        for (int i = 0; i < n; i++)
        {
            s.push_back('.');
        }
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(s);
        }
        solve(0, n, v);
        return ans;
    }
};
class Solution
{
    public:
        int A[300][300];
    bool matchReplacement(string s, string sub, vector<vector < char>> &mps)
    {

        memset(A, 0, sizeof(A));
        for (auto x: mps)
        {
            A[x[0] - '0'][x[1] - '0'] = 1;
        }
        for (int i = 0; i < sub.size(); i++)
        {
            A[sub[i] - '0'][sub[i] - '0'] = 1;
        }
        int n = s.size();
        int m = sub.size();
        for (int i = 0; i < n; i++)
        {
            int l = n - i;
            if (l < m) continue;
            int f = 1;
            l = 0;
            for (int j = i; j < n; j++)
            {
                if (A[(sub[l] - '0')][(s[j] - '0')] == 0)
                {
                    f = 0;
                    break;
                }
                l++;
                if(l==m)return 1;
            }
        }
        return 0;
    }
};
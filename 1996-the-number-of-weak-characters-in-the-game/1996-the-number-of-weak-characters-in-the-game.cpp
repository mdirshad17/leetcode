class Solution
{
    public:
        const static int N = 1e5 + 2;
    int numberOfWeakCharacters(vector<vector < int>> &P)
    {
        vector<int> v[N];
        for (auto x: P)
        {
            v[x[0]].push_back(x[1]);
        }
        int ans = 0;
        int maxl = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            int mxh = 0;
            for (auto x: v[i])
            {
                if (x < maxl)
                {
                    ans += 1;
                }
                mxh = max(mxh, x);
            }
            maxl = max(maxl, mxh);
        }
        return ans;
    }
};
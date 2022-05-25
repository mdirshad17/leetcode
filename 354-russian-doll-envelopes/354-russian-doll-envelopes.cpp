class Solution
{
    public:
    const static int N = 1e5 + 5;
    int SGT[4*N];
    int v[N];
    void update(int idx, int s, int e, int si, int val)
    {
        if (s == e)
        {
            SGT[si] = val;
            return;
        }
        int m = (s + e) / 2;
        if (idx <= m)
            update(idx, s, m, 2 *si + 1, val);
        else update(idx, m + 1, e, 2 *si + 2, val);

        SGT[si] = max(SGT[2*si + 1], SGT[2*si + 2]);
    }
    int q(int l, int r, int s, int e, int si)
    {
        if (l > r || l > e || r < s)
            return 0;
        if (s >= l && e <= r)
            return SGT[si];
        int m = (s + e) / 2;
        return max(q(l, r, s, m, 2 *si + 1), q(l, r, m + 1, e, 2 *si + 2));
    }
    int maxEnvelopes(vector<vector < int>> &en)
    {
        sort(en.begin(), en.end(), [](vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0])
            {
                return a[1] < b[1];
            }
            return a[0] < b[0];
	});
        vector<int> a[100005];
        int n = 100005;
      
        // for (int i = 0; i < 100005; i++)
        // {
        //     update(i, 0, 100004, 0, 0);
        // }
        for (auto x: en)
        {
            a[x[0]].push_back(x[1]);
        }
        int ans = 0;
        for (int i = 1; i < 100001; i++)
        {
            vector<int> vx;
            for (int x: a[i])
            {
                int l = q(0, x - 1, 0, n - 1, 0);
                ans = max(ans, l + 1);
                vx.push_back(l + 1);
            }
            int j = 0;
            for (int x: a[i])
            {

                if (v[x] < vx[j])
                {
                    v[x] = vx[j];
                    update(x, 0, n - 1, 0, v[x]);
                }
                j++;
            }
        }
        return ans;
    }
};
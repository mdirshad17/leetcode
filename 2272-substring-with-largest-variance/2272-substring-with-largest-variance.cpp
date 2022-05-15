class Solution
{
    public:
        const static int N = 1e4 + 5;
    int v[N];
    int pr[N];
    int solve(string &s, char a, char b)
    {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == a)
            {
                v[i] = 1;
            }
            else if (s[i] == b)
            {
                v[i] = -1;
            }
            else v[i] = 0;
            pr[i] = 0;
        }
        int pri = -1;
        for (int i = 0; i < n; i++)
        {

            if (i > 0) v[i] += v[i - 1];

            pr[i] = min(pr[i], v[i]);
            if (i != 0)
            {
                pr[i] = min(pr[i - 1], pr[i]);
            }
            if (s[i] == b)
            {
                pri = i;
            }
            if (pri != -1 && s[i] == a)
            {
                int sum = v[i] - (pri - 1 >= 0 ? pr[pri - 1] : 0);
                ans = max(ans, sum);
            }
        }

        return ans;
    }
    int largestVariance(string s)
    {
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i == j) continue;
                int l = solve(s, ('a' + i), ('a' + j));
                if (l == 0) continue;
               	// cout<<l<<" "<<i<<" "<<j<<endl;
                ans = max(ans, l);
            }
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i == j) continue;
                int l = solve(s, ('a' + i), ('a' + j));
                if (l == 0) continue;
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
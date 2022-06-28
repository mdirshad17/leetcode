class Solution
{
    public:
        int minDeletions(string s)
        {
            int n = s.size();
            int a[26];
            memset(a, 0, sizeof(a));
            for (int i = 0; i < n; i++)
            {
                a[s[i] - 'a']++;
            }
            sort(a, a + 26);
            int ans = 0;
            while (1)
            {
                int cnt = 0;
                int f = 0;
                for (int i = 0; i < 26; i++)
                {
                   	// cout<<a[i]<<" ";
                    if (a[i] == 0) continue;
                    if (i != 0 && a[i] == a[i - 1])
                    {
                        cnt++;
                    }
                    else
                    {
                        int add = max(cnt - 1, 0);
                       	// cout<<add<<" ";
                        if (cnt > 1) f = 1;
                        ans += add;
                        cnt = 1;
                    }
                }
                int add = max(cnt - 1, 0);
               	// cout<<add<<" ";
                if (cnt > 1) f = 1;
                ans += add;
                for (int i = 0; i < 26; i++)
                {
                    if (a[i] == 0) continue;
                    if (i != 0 && a[i] == a[i - 1])
                    {
                        a[i - 1] -= 1;
                    }
                }
                sort(a, a + 26);
                if (f == 0) break;
            }
            return ans;
        }
};
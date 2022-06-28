class Solution
{
    public:
        int minDeletions(string s)
        {
            int n = s.size();
            int cnt[n+1];
            int a[26]{};
            memset(cnt, 0, sizeof(cnt));
            
            for (int i = 0; i < n; i++)
            {
                a[s[i] - 'a']++;
            }
            int ans=0;
            for (int i = 0; i < 26; i++)
            {
                if (a[i] == 0) continue;
                int ab = 0;
                for (int j = a[i]; j >= 0; j--)
                {
                    if (cnt[j] == 0)
                    {
                        ab = j;
                        break;
                    }
                }
                cnt[ab]=1;
                ans+=(a[i]-ab);
            }
            return ans;
            
        }
};
class Solution
{
    public:
        int romanToInt(string s)
        {
            int n = s.size();
            map<char, int> mp;
            mp['I'] = 1;
            mp['V'] = 5;
            mp['X'] = 10;
            mp['L'] = 50;
            mp['C'] = 100;
            mp['D'] = 500;
            mp['M'] = 1000;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int a = mp[s[i]];
                if (i + 1 < n)
                {
                    int b = mp[s[i + 1]];
                    if (b > a)
                        ans -= a;
                    else ans += a;
                }
                else
                {
                    ans += a;
                }
                // cout << ans << endl;
            }
            return ans;
        }
};
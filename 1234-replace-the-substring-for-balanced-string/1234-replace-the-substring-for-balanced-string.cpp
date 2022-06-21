class Solution
{
    public:
#define ll long long

    unordered_map<char, int> mpx, mpg;
    int enough_extra(int extra)
    {
        int l = min(mpg['Q'], mpx['Q']);
        int m = min(mpg['W'], mpx['W']);
        int n = min(mpg['E'], mpx['E']);
        int o = min(mpg['R'], mpx['R']);

        return ((l + m + n + o) >= extra);
    }

    int balancedString(string s)
    {
        int n = s.size();
        int ans = n;
        unordered_map<char, int> mp;
        for (char c: s)
        {
            mp[c]++;
        }
        int extra = 0;
        for (auto x: mp)
        {
            if (x.second > n / 4)
            {
                mpx[x.first] = (x.second - n / 4);
                extra += (x.second - n / 4);
            }
        }
       	// cout<<extra<<endl;
        if (extra <= 1) return extra;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            mpg[s[i]]++;
            while (enough_extra(extra))
            {
                ans = min(ans, i - j + 1);
                mpg[s[j]]--;
                j++;
            }
        }
        return ans;
    }
};
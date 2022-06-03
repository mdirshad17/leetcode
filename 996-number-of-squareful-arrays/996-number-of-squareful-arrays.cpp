class Solution
{
    public:

        int get(int n)
        {
            int cnt = 0;
            while (n)
            {
                cnt++;
                n -= (n &-n);
            }
            return cnt;
        }
    int good(int num)
    {

        int l = floor(sqrt(num));
        int m = ceil(sqrt(num));
        return (l == m);
    }
    int dp[15][(1<<15)];
    int solve(int mask, vector<int> &v, int pn)
    {
        int cnt = get(mask);
        if (cnt >= v.size()) return 1;
        
        if(dp[pn][mask]!=-1)return dp[pn][mask];
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if ((mask &(1 << i))) continue;
            int pr=v[pn];
            if (good(pr + v[i]))
            {
                ans += solve((mask | (1 << i)), v, i);
            }
        }
        return dp[pn][mask]=ans;
    }
    int numSquarefulPerms(vector<int> &nums)
    {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            ans += solve((1 << i), nums, i);
        }
        int fact[13];
        fact[0] = 1;
        for (int i = 1; i <= 12; i++)
        {
            fact[i] = (i *fact[i - 1]);
        }
        for(auto x:mp){
            ans=ans/fact[x.second];
        }
        return ans;
    }
};
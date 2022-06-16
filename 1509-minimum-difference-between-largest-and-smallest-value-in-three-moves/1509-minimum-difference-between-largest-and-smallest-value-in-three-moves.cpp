class Solution
{
    public:
#define ll long long
    int good(vector<int> &nums, ll m)
    {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while ((nums[i] - nums[j]) > m)
            {
                j++;
            }
            int leftout = (n - (i - j + 1));
            if (leftout <= 3) return 1;
        }
        return 0;
    }
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        // if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        ll l = 0, r = 2e9 + 2;
        int ans = r;
        while (l <= r)
        {
            ll m = (l *1LL + r *1LL) / 2LL;
            if (good(nums, m))
            {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};
class Solution
{
    public:
#define ll long long
    int good(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j = 0;
        int ans = INT_MAX;
        int ops = n - 3;
        if(ops<=1)return 0;
        for (int i = 0; i < n; i++)
        {
            while ((i - j + 1) > ops)
            {
                j++;
            }
            if ((i - j + 1) >= ops)
            {
                ans = min(ans, (nums[i] - nums[j]));
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
    int minDifference(vector<int> &nums)
    {
        return good(nums);
    }
};
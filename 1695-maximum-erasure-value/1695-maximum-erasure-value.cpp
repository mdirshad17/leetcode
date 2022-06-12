class Solution
{
    public:
        int maximumUniqueSubarray(vector<int> &nums)
        {
            int n = nums.size();
            int sum = 0;
            int ans = 0;
            int j = 0;
            map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                mp[nums[i]]++;
                sum += nums[i];
                while (mp[nums[i]]>1)
                {
                    mp[nums[j]]--;
                    sum-=nums[j];
                    j++;
                }
                ans = max(ans, sum);
            }
            return ans;
        }
};
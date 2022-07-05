class Solution
{
    public:
        int totalHammingDistance(vector<int> &nums)
        {
            int ans = 0;
            
            int n = nums.size();
            for (int i = 0; i <= 31; i++)
            {
                int num = (1 << i);
                int cnt=0;
                for (int j = 0; j < n; j++)
                {
                    if ((num &nums[j]))
                    {
                       cnt++;
                    }
                }
                int unset=n-cnt;
                ans+=cnt*unset;
            }
            return ans;
            
        }
};
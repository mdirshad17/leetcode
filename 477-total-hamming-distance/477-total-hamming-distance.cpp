class Solution
{
    public:
        int totalHammingDistance(vector<int> &nums)
        {
            int arr[32];
            int n = nums.size();
            memset(arr, 0, sizeof(arr));
            for (int i = 0; i <= 31; i++)
            {
                int num = (1 << i);
                for (int j = 0; j < n; j++)
                {
                    if ((num &nums[j]))
                    {
                        arr[i]++;
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i <= 31; i++)
            {
                int setbit = arr[i];
                int unsetbit = n - arr[i];
                ans = ans + (setbit *unsetbit);
            }
            return ans;
        }
};
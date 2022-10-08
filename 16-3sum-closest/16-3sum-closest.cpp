class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int T = target;
            int ans;
            int diff = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                int j = i + 1, k = n - 1;
                int csum;
                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == T)
                    {
                        return T;
                    }
                    int diffh = abs(sum - T);
                    if (diffh < diff)
                    {
                        ans = sum;
                        diff = diffh;
                    }
                    if (sum > T) {
                        k--;
                    }else j++;
                }
            }
            return ans;
        }
};
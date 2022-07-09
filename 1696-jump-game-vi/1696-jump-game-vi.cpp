class Solution
{
    public:
        const static int N = 1e5 + 10;
    int dp[N];
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        multiset<int> mt;
        mt.insert(-nums[n - 1]);
        dp[n-1]=nums[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            auto it = mt.begin();
            int val = (*it);
            dp[i] = nums[i] - val;
            if ((i + k) < n)
            {
                // cout<<mt.size()<<endl;
                mt.erase(mt.find(-dp[i + k]));
            }
            mt.insert(-dp[i]);
        }
        return dp[0];
    }
};
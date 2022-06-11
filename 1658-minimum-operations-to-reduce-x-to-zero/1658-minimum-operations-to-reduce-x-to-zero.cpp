class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int tot = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                tot += nums[i];
            }
            if(tot==x)return n;
            int req = tot - x;
            // if(req==0)return n;
            unordered_map<int, int> mp;
            mp[0]=-1;
            int len = -1;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += nums[i];
                if (mp.count(sum - req))
                {
                    int idx = mp[sum-req];
                    int ln = i - idx;
                    len = max(len, ln);
                }
                mp[sum] = i;
            }
            cout<<len<<" "<<req<<" "<<tot<<endl;
            if(len==-1)return len;
            return n-len;
        }
};
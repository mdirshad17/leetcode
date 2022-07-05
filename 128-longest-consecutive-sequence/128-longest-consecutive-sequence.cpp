class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            unordered_set<int> st;
            for (int x: nums) st.insert(x);
            int ans = 0;
            for (int x: nums)
            {
                int cnt = 1;
                if (!st.count(x - 1))
                {
                    while (st.count(x + 1))
                    {
                        x++;
                        cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
            return ans;
        }
};
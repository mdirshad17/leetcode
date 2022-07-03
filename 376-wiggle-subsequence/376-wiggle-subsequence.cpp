class Solution
{
    public:
          int dp[1005][1005][2];  
        int solve(int s, int n, vector<int> &nums, int f, int p)
        {
            if (s >= n) return 0;
            if(dp[s][f+1][p]!=-1)return dp[s][f+1][p];
            int op1 = solve(s + 1, n, nums ,f, p);
            int op2 = 0;
            
            if (f == -1)
            {
                int a = 1+solve(s + 1, n, nums, s, 1);
                int b = 1+solve(s + 1, n, nums, s, 0);
                op2 = max(a, b);
            }
            else
            {
                if (p == 1)
                {
                    if (nums[s] > nums[f]) op2 = 1+solve(s + 1, n, nums, s, 0);
                }
                else
                {
                    if (nums[s] < nums[f]) op2 = 1+solve(s + 1, n, nums, s, 1);
                }
            }
            return dp[s][f+1][p]=max(op1, op2);
        }
    int wiggleMaxLength(vector<int> &nums)
    {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int l = solve(0, n, nums, -1, 0);
        return l;
    }
};
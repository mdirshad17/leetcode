class Solution
{
    public:
#define ll long long
    void solve(int s, int n, vector<int> &v, vector<int> V[], int sum, int cnt)
    {
        if (s >= n)
        {
            V[cnt].push_back(sum);
            return;
        }
        solve(s + 1, n, v, V, sum + v[s], cnt + 1);
        solve(s + 1, n, v, V, sum - v[s], cnt);
    }
    void printv(vector<int> &v)
    {
        for (int x: v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    int minimumDifference(vector<int> &nums)
    {
        int ni = nums.size();
        int n = ni / 2;
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            a.push_back(nums[i]);
            b.push_back(nums[i + n]);
        }
        vector<int> A[16], B[16];
        for (int i = 0; i <= 15; i++)
        {
            B[i].push_back(INT_MIN);
            B[i].push_back(INT_MAX);
        }
        ll ans = LONG_MAX;
        solve(0, n, a, A, 0, 0);
        solve(0, n, b, B, 0, 0);
        for(int i=0;i<=15;i++){
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
        }
        // printv(A);
        // printv(B);
        for (int i = 0; i <= n/2; i++)
        {   
         
            for (auto x: A[i])
            {
                
                int Ai = x;
                int idx1 = lower_bound(B[i].begin(), B[i].end(), Ai) - B[i].begin();
                if (B[i][idx1] == Ai) return 0;
                idx1--;
                ll num1 = B[i][idx1];
                ll diff = abs(num1-Ai*1LL);
                ans = min(ans, diff);
                int idx2 = upper_bound(B[i].begin(), B[i].end(), Ai) - B[i].begin();
                ll num2 = B[i][idx2];
                diff = abs(num2-Ai*1LL);
                ans = min(ans, diff);
            }
        }
        return ans;
    }
};
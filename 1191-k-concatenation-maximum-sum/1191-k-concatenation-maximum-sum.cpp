class Solution
{
    public:
#define ll long long
#define M 1000000007
    ll kadane(vector<int> &arr)
    {
        int n = arr.size();
        ll cm = 0, mm = 0;
        for (int i = 0; i < n; i++)
        {
            cm = max(cm + arr[i], arr[i]*1LL);
            mm = max(mm, cm);
        }
        return mm % M;
    }
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {

        if (k == 1) return kadane(arr);

        ll sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if (sum <= 0 || k == 2)
        {
            vector<int> new_v;
            for (int x: arr)
            {
                new_v.push_back(x);
            }
            for (int x: arr)
            {
                new_v.push_back(x);
            }
            return kadane(new_v);
        }
        ll prefx = 0;
        ll suff = 0;
        ll sumx = 0;
        for (int i = 0; i < n; i++)
        {
            sumx += arr[i];
            prefx = max(prefx, sumx);
        }
        sumx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sumx += arr[i];
            suff = max(suff, sumx);
        }
        ll middle = ((k - 2) *1LL *sum) % M;
        ll tot_max = (middle + suff + prefx) % M;
        return tot_max;
    }
};
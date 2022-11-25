class Solution
{
    public:
#define M 1000000007
#define ll long long
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        int left[n];
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (st.size() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (st.size())
            {
                left[i] = st.top();
            }
            else left[i] = -1;
            st.push(i);
        }
        while (st.size())
        {
            st.pop();
        }
        int right[n];
        // stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.size())
            {
                right[i] = st.top();
            }
            else right[i] = n;
            st.push(i);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ll lft=i-left[i];
            ll rt=right[i]-i;
            ll contr=(arr[i]*1LL*lft*rt)%M;
            contr=contr%M;
            ans+=contr;
            ans=ans%M;
        }
        return ans;
    }
};
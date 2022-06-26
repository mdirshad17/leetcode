class Solution
{
    public:
        int largestRectangleArea(vector<int> &h)
        {
            int n = h.size();
            stack<int> st;
            int left[n];
            int right[n];
            for (int i = 0; i < n; i++)
            {
                while (st.size() && h[i] <= h[st.top()])
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
            while (st.size()) st.pop();

            for (int i = n - 1; i >= 0; i--)
            {
                while (st.size() && h[i] <= h[st.top()])
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
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int width = (right[i] - left[i] - 1);
                int height = h[i];
                int area = width * height;
                ans = max(ans, area);
            }
            return ans;
        }
};
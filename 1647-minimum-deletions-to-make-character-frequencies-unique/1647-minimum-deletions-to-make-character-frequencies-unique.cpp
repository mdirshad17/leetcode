class Solution
{
    public:
        int minDeletions(string s)
        {
            set<int> st;
            int n = s.size();
            int a[26];
            memset(a, 0, sizeof(a));
            for (int i = 0; i < n; i++)
            {
                st.insert(i);
                a[s[i] - 'a']++;
            }
            int ans = 0;
            st.insert(n);
            for (int i = 0; i < 26; i++)
            {
                if (a[i] == 0) continue;
                if (st.count(a[i]))
                {
                    st.erase(a[i]);
                }
                else
                {
                    auto it = st.lower_bound(a[i]);
                    (--it);
                    int val = (*it);
                    ans += (a[i] - val);
                    if (val)
                    {
                        st.erase(it);
                    }
                }
            }
            return ans;
        }
};
class Solution
{
    public:
        string replaceit(string s)
        {
            int n = s.size();
            string res;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '-')
                {
                    if (res.back() == '(')
                    {
                        res.push_back('0');
                    }
                    res.push_back(s[i]);
                }
                else res.push_back(s[i]);
            }
           	// cout<<res<<" ";
            return res;
        }
    int calculate(string s)
    {

        stack<int> st;
        s=replaceit(s);
        st.push(1);
        st.push(1);
        int ans = 0;
        int i = 0;
        int n = s.size();
        for (; i < n;)
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else if (s[i] == '(')
            {
                st.push(st.top());
                i++;
            }
            else if (isdigit(s[i]))
            {
                int num = 0;
                while (i < n && isdigit(s[i]))
                {
                    num = num *10 + (s[i] - '0');
                    i++;
                }
                ans += (st.top() *num);
                st.pop();
               	// cout<<ans<<" ";
            }
            else if (s[i] == '+')
            {
                st.push(st.top());
                i++;
            }
            else if (s[i] == '-')
            {
                st.push(st.top() *-1);
                i++;
            }
            else if (s[i] == ')')
            {
                st.pop();
               	// cout<<"Hello orld";
                i++;
            }
        }
        return ans;
    }
};
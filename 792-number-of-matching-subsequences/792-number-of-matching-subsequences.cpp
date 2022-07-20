class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> &words)
        {
            vector<int> v[26];
            int n = s.size();
            for (int i = 0; i < n; i++)
            {
                v[s[i] - 'a'].push_back(i);
            }
            for (int i = 0; i < 26; i++)
            {
                v[i].push_back(INT_MAX);
            }
            int ans = 0;
            for (auto x: words)
            {
                string g = x;
                int prev = -1;
                int flag = 1;
                for (int i = 0; i < g.size(); i++)
                {
                    int val = g[i] - 'a';

                    auto idx = upper_bound(v[val].begin(), v[val].end(), prev) - v[val].begin();
                    idx = v[val][idx];
                    if (idx == INT_MAX)
                    {
                        flag = 0;
                        break;
                    }
                    prev = idx;
                }
                
                if (flag){
                    ans++;
                    // cout<<x<<endl;
                }
            }
            return ans;
        }
};
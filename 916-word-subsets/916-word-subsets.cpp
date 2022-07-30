class Solution
{
    public:
        vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
        {
            int a[26] = { 0 };
            vector<string> res;
            for (string s: words2)
            {
                int b[26] = { 0 };
                int n=s.size();
                for (int i = 0; i < n; i++)
                {
                    b[s[i] - 'a']++;
                }
                for (int i = 0; i < 26; i++)
                {
                    a[i] = max(a[i], b[i]);
                }
            }
            for (string s: words1)
            {
                int b[26] = { 0 };
                int n=s.size();
                for (int i = 0; i < n; i++)
                {
                    b[s[i] - 'a']++;
                }
                int f = 1;
                for (int i = 0; i < 26; i++)
                {
                    if (b[i] < a[i])
                    {
                        f = 0;
                        break;
                    }
                }
                if (f)
                {
                    res.push_back(s);
                }
            }
            return res;
        }
};
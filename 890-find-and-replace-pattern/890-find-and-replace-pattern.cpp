class Solution
{
    public:
        int match(string &s, string &p)
        {
            int n = s.size();
            int m = p.size();
            if (n != m) return 0;
            // return 0;
            map<char, char> s_p, p_s;
            for (int i = 0; i < n; i++)
            {
                if (s_p.count(s[i]) && p_s.count(p[i]))
                {
                    if (s_p[s[i]] != p[i] || p_s[p[i]] != s[i]) return 0;
                    
                    continue;
                }
                if (s_p[s[i]] || p_s[p[i]]) return 0;
                s_p[s[i]] = p[i];
                p_s[p[i]] = s[i];
            }
            return 1;
        }
    vector<string> findAndReplacePattern(vector<string> &w, string p)
    {
        vector<string> res;
        for (string s: w)
        {
            int l = match(s, p);
            if (l) res.push_back(s);
        }
        return res;
    }
};
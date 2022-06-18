class WordFilter
{
    public:
#define ll long long
#define M 1000000007
#define M1 1000000007    
    const static ll p = 31;
   	const ll m = 1e9 + 9;
    
    ll p_pow[15];
    void ppx()
    {
        p_pow[0] = 1;
        for (int i = 1; i < 15; i++)
            p_pow[i] = (p_pow[i - 1] *p *1LL) % M;
    }
    ll get(string s)
    {

        ll num = 0;
        ll numr = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            num += (num + (s[i] - 'a' + 1) *p_pow[i]) % M;
             numr += (numr + (s[i] - 'a' + 1) *p_pow[i]) % m;
            
        }
        ll sum=((num*m+numr*M)%M)%M;
        return sum;
    }
    map<pair<ll,ll>, int> mp;
    void process(string &s, int num)
    {
        int n = s.size();
        vector<ll> a, b;
        string g;
        for (int i = 0; i < n; i++)
        {
            g.push_back(s[i]);
            a.push_back(get(g));
        }
        string f;
        for (int i = n-1; i>=0; i--)
        {
            f.push_back(s[i]);
            reverse(f.begin(), f.end());
            b.push_back(get(f));
            reverse(f.begin(), f.end());
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pair<ll,ll> finals={a[i],b[j]};
                
                mp[finals] = max(mp[finals], num);
            }
        }
    }
    WordFilter(vector<string> &words)
    {
        ppx();
        unordered_map<string, int> mps;

        int n = words.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (mps.count(words[i])) continue;
            mps[words[i]] = 1;
            process(words[i], i);
        }
    }

    int f(string p, string s)
    {

        pair<ll,ll> a={get(p),get(s)};
        if(mp.count(a))return mp[a];
        return -1;
    }
};

/**
 *Your WordFilter object will be instantiated and called as such:
 *WordFilter* obj = new WordFilter(words);
 *int param_1 = obj->f(prefix,suffix);
 */
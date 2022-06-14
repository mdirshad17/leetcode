class Solution
{
    public:
        int minDistance(string s, string p)
        {
            vector<int> v[26];
            for (int i = s.size() - 1; i >= 0; i--)
            {
                v[s[i] - 'a'].push_back(i);
            }
            vector<int> sq;
            for (int i = 0; i < p.size(); i++)
            {
                int num = p[i] - 'a';
                for (int j = 0; j < v[num].size(); j++)
                {
                    sq.push_back(v[num][j]);
                }
            }
            int n=s.size();
            int m=p.size();
            if(sq.size()==0)return (n+m);
            int ans = 1;
            vector<int> seq;
            seq.push_back(sq[0]);
            for (int i = 1; i < sq.size(); i++)
            {
                if (sq[i] > seq.back())
                {
                    seq.push_back(sq[i]);
                }
                else
                {
                    auto it = lower_bound(seq.begin(), seq.end(), sq[i]) - seq.begin();
                    seq[it] = sq[i];
                }
            }
            int len=seq.size();
            return (n+m-(2*len));
        }
};
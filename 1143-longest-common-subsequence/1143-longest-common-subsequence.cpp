class Solution
{
    public:
        int longestCommonSubsequence(string text1, string text2)
        {
            vector<int> v;
            vector<int> a[26];
            for (int i = 0; i < text1.size(); i++)
            {
                a[text1[i] - 'a'].push_back(i);
            }
            for (int i = 0; i < text2.size(); i++)
            {
                int n = a[text2[i] - 'a'].size();
                for (int j = n - 1; j >= 0; j--)
                {
                    v.push_back(a[text2[i] - 'a'][j]);
                }
            }
            if (v.size() == 0)
            {
                return 0;
            }
            // for (int x: v)
            // {
            //     cout << x << " ";
            // }
           	// cout << endl;
            vector<int> seq;
            seq.push_back(v[0]);
           	// seq.push_back(-1);
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] > seq.back())
                {
                    seq.push_back(v[i]);
                }
                else
                {
                    auto it = lower_bound(seq.begin(), seq.end(), v[i]) - seq.begin();
                    seq[it] = v[i];
                }
            }
            return (seq.size());
        }
};
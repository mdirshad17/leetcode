class Solution
{
    public:
        int maxProduct(vector<string> &words)
        {

            vector<int> mask;
            int n = words.size();
            for (int i = 0; i < n; i++)
            {
                int num = 0;
                for (auto x: words[i])
                {
                    num = (num | (1 << (x - 'a')));
                }
                mask.push_back(num);
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
            {

                int len = words[i].size();
                int len2 = 0;
                for (int j = i + 1; j < n; j++)
                {
                    if ((mask[i] &mask[j])) continue;
                    int l = words[j].size();
                    len2 = max(len2, l);
                }
                ans = max(ans, (len *len2));
            }
            return ans;
        }
};
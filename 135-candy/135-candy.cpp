class Solution
{
    public:
        int candy(vector<int> &rat)
        {
            auto compare =[& rat](int i, int j)
            {
                return rat[i] > rat[j];
            };
            int n = rat.size();
            int res[n];
            memset(res, 0, sizeof(res));
            priority_queue<int, vector < int>,decltype(compare)> pq(compare);
            for (int i = 0; i < n; i++)
            {
                res[i] = 1;
                pq.push(i);
            }
            while (pq.size())
            {
                int d = pq.top();
                pq.pop();
                // cout<<d<<endl;
                // cout<<res
                if ((d >= 1) && rat[d] < rat[d - 1])
                {
                    res[d - 1] = max(res[d-1],res[d]+1);
                }
                if ((d + 1) < n && rat[d] < rat[d + 1])
                {
                    res[d + 1] = max(res[d+1],res[d]+1);
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += res[i];
            }
            return ans;
        }
};
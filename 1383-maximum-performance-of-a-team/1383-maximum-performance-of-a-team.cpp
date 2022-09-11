class Solution
{
    public:
#define ll long long
#define M 1000000007
#define pii pair<ll, ll>
        int maxPerformance(int n, vector<int> &S, vector<int> &E, int k)
        {
            vector<pii> SE;
            for (int i = 0; i < n; i++)
            {
                SE.push_back({ E[i],
                    S[i] });
            }
            sort(SE.begin(), SE.end(), [](pii &a, pii &b)
            {
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
	});
            priority_queue<ll, vector < ll>, greater < ll>> pq;
            ll sum = 0;
            ll ans=0;
            for (int i = 0; i < k; i++)
            {
                pq.push(SE[i].second);
                sum += SE[i].second;
                ans=max(ans,sum*1LL*SE[i].first);
            }
            for (int i = k; i < n; i++)
            {
                sum += SE[i].second;
                pq.push({ SE[i].second });
                sum -= pq.top();
                pq.pop();
                
                ll prod = sum *1LL *SE[i].first *1LL;
                ans = max(ans, prod);
            }
            return ans % M;
        }
};
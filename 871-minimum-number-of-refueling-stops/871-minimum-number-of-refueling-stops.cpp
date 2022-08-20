class Solution
{
    public:
        int minRefuelStops(int dist, int fuel, vector<vector < int>> &S)
        {
            if (fuel >= dist) return 0;
            priority_queue<int> pq;
            int n = S.size();
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                while (pq.size() && fuel < S[i][0])
                {
                    fuel += pq.top();
                    pq.pop();
                    cnt++;
                }
                if (fuel < S[i][0]) return -1;
                pq.push(S[i][1]);
            }
            while (pq.size() && fuel <dist)
            {
                fuel += pq.top();
                pq.pop();
                cnt++;
            }
            if(fuel<dist)return -1;
            return cnt;
        }
};
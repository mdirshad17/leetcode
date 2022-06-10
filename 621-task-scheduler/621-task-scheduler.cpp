class Solution
{
    public:
#define pii pair<int, int>
        int leastInterval(vector<char> &tasks, int n)
        {
            if (n == 0) return tasks.size();
            priority_queue<pair<int, int>> pq;
            priority_queue<pii, vector < pii>, greater < pii>> pq1;
            sort(tasks.begin(), tasks.end());
            int cnt = 1;
            for (int i = 1; i < tasks.size(); i++)
            {
                if (tasks[i] == tasks[i - 1])
                {
                    cnt++;
                }
                else
                {
                    pq.push({ cnt,
                        1 });
                    cnt = 1;
                }
            }
            pq.push({ cnt,
                1 });
            int time = 1;

            while (pq.size() || pq1.size())
            {
               	// cout<<pq.size()<<" ";
                if (pq.size())
                {
                    pii d = pq.top();
                    pq.pop();
                   	// cout<<d.first<<" "<<d.second<<" "<<time<<endl;
                   	// d.first--;
                    if ((d.first - 1) != 0)
                    {
                        int timer=max(time,d.second)+n+1;
                        pq1.push({ timer,
                            (d.first - 1) });
                    }
                }
                time++;
                while (pq1.size() && (pq1.top().first) <=time)
                {
                    pii dt = pq1.top();
                    pq.push({ dt.second,dt.first});
                    pq1.pop();
                }
                
            }
            return (time-1);
        }
};
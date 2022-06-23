class Solution
{
    public:
        int scheduleCourse(vector<vector < int>> &courses)
        {
            int n = courses.size();
            priority_queue<int> pq;
            sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b)
            {
                return a[1] < b[1];
	});
            pq.push(0);
            int t = 0;
            int ans = 0;
            // for (int i = 0; i < n; i++)
            // {
            //     cout << courses[i][0] << " " << courses[i][1] << endl;
            // }
            for (int i = 0; i < n; i++)
            {
                if ((t + courses[i][0]) <= courses[i][1]){
                
                    pq.push(courses[i][0]);
                    t = t + courses[i][0];
                }
                else
                {
                    if (pq.top() > courses[i][0])
                    {
                        t -= pq.top();
                        if (t + courses[i][0] <= courses[i][1])
                        {
                            pq.pop();
                            pq.push(courses[i][0]);
                            t=t + courses[i][0];
                        }
                    }
                }
                // cout<<t<<" "<<pq.size()<<endl;
                ans = max(ans, (int) pq.size()-1);
            }
            return ans;
        }
};
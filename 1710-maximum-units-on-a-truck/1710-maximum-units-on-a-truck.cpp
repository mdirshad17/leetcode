class Solution
{
    public:
        int maximumUnits(vector<vector < int>> &boxTypes, int t)
        {
            sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b)
            {
                return (a[1] > b[1]);
	});
            int ans = 0;
            for (auto x: boxTypes)
            {
                int u = x[0];
                int v = x[1];
                // cout<<u<<" "<<v<<endl;
                int l = min(u, t);
                t -= l;
                ans += (l *v);
            }
            return ans;
        }
};
class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n=q.size();
        priority_queue<int> pq;
        vector<pair<double,int> > vp;
        for(int i=0;i<n;i++){
           double ratio=(1.0*w[i]/q[i]);
            vp.push_back({ratio,q[i]});
        }
        sort(vp.begin(),vp.end(),[](pair<double,int> & a,pair<double,int> & b){
             return a.first<b.first; 
        });
        double res=0;
        double sum=0;
        for(int i=0;i<k-1;i++){
            sum+=vp[i].second;
            pq.push(vp[i].second);
        }
        double minCost=INT_MAX;
        // cout<<sum<<" ";
        for(int i=k-1;i<n;i++){
            double f=(vp[i].first*vp[i].second);
            double r=vp[i].first;
            double cost=(sum*vp[i].first+f);
            minCost=min(minCost,cost);
            pq.push(vp[i].second);
            sum+=vp[i].second;
            sum-=pq.top();
            pq.pop();
        }
        return minCost;
        
    }
};
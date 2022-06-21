class Solution {
public:
    #define ll long long 
    int furthestBuilding(vector<int>& h, int b, int lad) 
    {
        int n=h.size();
        ll sum=0;
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<n;i++){
            ll diff=h[i]-h[i-1];
            if(diff<=0)diff=0;
            pq.push(diff);
            if(pq.size()>lad){
                sum+=pq.top();
                pq.pop();
            }
            if(sum>b)break;
            ans=i;
        }
        return ans;
    }
};
class Solution {
public:
    #define ll long long 
    int good(vector<int> & h,int m,int b,int l){
        int n=h.size();
        priority_queue<ll> pq;
        
        for(int i=1;i<=m;i++){
            int diff=h[i]-h[i-1];
            if(diff<=0)continue;
            pq.push(diff);
            
        }
        while(l-- && pq.size()){
            pq.pop();
        }
        ll sum=0;
        while(pq.size()){
            sum+=pq.top();
            pq.pop();
        }
        return (sum<=b);
        
        
    }
    int furthestBuilding(vector<int>& h, int b, int lad) {
        int n=h.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            int m=(l+r)/2;
            if(good(h,m,b,lad)){
                ans=m;
                l=m+1;
            }else r=m-1;
        }
        return ans;
    }
};
class Solution {
public:
    const static int N=1e5+10;
    #define pii pair<int,int>
        pii SGT[4 * N];
     
void update(int idx, int s, int e, int si, int val)
{
    if (s == e)
    {
        SGT[si] = {val,idx};
        return;
    }
    int m = (s + e) / 2;
    if (idx <= m)
        update(idx, s, m, 2 * si + 1, val);
    else update(idx, m + 1, e, 2 * si + 2, val);

    if(SGT[2*si+1].first>SGT[2*si+2].first){
        SGT[si]=SGT[2*si+1];
    }else SGT[si]=SGT[2*si+2];
}
pii q(int l, int r, int s, int e, int si)
{
    if (l > r || l > e || r < s)
        return {-1,-1};
    if (s >= l && e <= r)
        return SGT[si];
    int m = (s + e) / 2;
    pii a=q(l, r, s, m, 2 * si + 1);  
    pii b=q(l, r, m + 1, e, 2 * si + 2);
    if(a.first>b.first) return a;
    else return b; 
}

    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
            int n=p.size();
            multiset<pii> st;
            vector<pair<int,int> > v;
            for(int i=0;i<p.size();i++){
                v.push_back({c[i],p[i]});
            }
            sort(v.begin(),v.end());
            for(int i=0;i<n;i++){
                update(i,0,n-1,0,v[i].second);
            }
            sort(c.begin(),c.end());
            // for(int i=0;i<n;i++){
            //     cout<<v[i].first<<" "<<v[i].second<<endl;
            // }
            
            // c.insert(INT_MAX);
        int cap=w;
        k=min(k,n);
            while(k--){
                auto it=(upper_bound(c.begin(),c.end(),cap))-c.begin();
                it--;
                // cout<<"IT "<<it<<endl;
                pii qr=q(0,it,0,n-1,0);
                // cout<<"qr "<<qr.first<<" \n";
                int l=0;
                // for(int i=0;i<=it;i++){
                //     l=max(l,v[i].second);
                // }
                // cout<<l<<" "<<qr.first<<endl;
                if(qr.first==-1)break;
                cap+=qr.first;
                update(qr.second,0,n-1,0,0);
            }
        // cout<<endl;
        return cap;
        
           
        
    }
};
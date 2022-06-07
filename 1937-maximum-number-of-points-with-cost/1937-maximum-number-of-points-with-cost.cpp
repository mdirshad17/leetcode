class Solution
{
    public:
#define ll long long
    long long maxPoints(vector<vector < int>> &p)
    {

        int n = p.size();
        int m = p[0].size();
        vector<ll> v(m);
        vector<ll> pref(m, 0);
        vector<ll> suff(m, 0);
        for (int i = n - 1; i >= 0; i--)
        {   
            
            for (int j = 0; j < m; j++)
            {
                 if(i==n-1){
                     v[j]=p[i][j];
                     continue;
                 }
                v[j] = p[i][j] + max(pref[j]-j, suff[j]+j);
            }
            // for(int j=0;j<m;j++){
            //     cout<<v[j]<<" ";
            // }cout<<endl;
            
            pref.clear();
            suff.clear();
            pref.assign(m, INT_MIN);
            suff.assign(m, INT_MIN);
            ll prefx=INT_MIN+10;
            ll suffx=INT_MIN+10;
            for (int j = 0; j < m; j++)
            {
                prefx=max(prefx,v[j]+j);
                pref[j]=prefx;
                // cout<<pref[j]<<" ";
            }
            // cout<<endl;
            for (int j = m - 1; j >= 0; j--)
            {
                suffx=max(suffx,v[j]-j);
                suff[j]=suffx;
                // cout<<suff[j]<<" ";
            }
            // cout<<endl<<endl;
            
        }
        return *max_element(v.begin(),v.end());
    }
};
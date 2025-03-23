class Solution {
public:
    const static int N=205;
    #define ll long long
    #define M 1000000007
    int countPaths(int n, vector<vector<int>>& roads) {
        set<vector<ll> > st;
        vector<pair<int,int>> adj[N];
        for(auto x:roads){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        st.insert({0,0,1});
        // int cnt[N];
        // memset(cnt,0,n+2);
        ll dp[N];
        ll cnt[N];
        memset(cnt,0,sizeof(cnt));
        cnt[0]=1;
        memset(dp,1,sizeof(dp));
        dp[0]=0;
        while(st.size()){
            auto it=(st.begin());
            ll wt=(*it)[0];
            int u=(*it)[1];
            ll ways=cnt[u]%M;
            st.erase(it);
            for(auto x:adj[u]){
               ll tw=(x.second)*1LL+wt;
                int nb=x.first;
                if(tw<dp[nb]){
                    // cout<<tw<<" "<<nb<<" "<<ways<<"\n";
                    st.erase({dp[nb],nb});
                    dp[nb]=tw;
                    cnt[nb]=ways%M;
                    st.insert({dp[nb],nb});
                }else if(tw==dp[nb]){
                    cnt[nb]+=ways;
                    cnt[nb]%=M;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     // cout<<dp[i]<<" "<<cnt[i]<<" Node : "<<i<<"\n";
        // }
        return cnt[n-1];
    }
};
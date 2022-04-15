class Solution {
public:
    map<int,int> mp;
    #define ll long long 
    #define M 1000000007 
    int n;
    ll dp[1005];
    ll solve(int p,vector<int> &v){
        if(dp[p]!=-1)return dp[p];
        ll ans=1;
        for(int i=0;i<n;i++){
            if((v[p]%v[i]))continue;
            int req=v[p]/v[i];
            if(mp.count(req)){
                ans+=(solve(i,v)*1LL*solve(mp[req],v)*1LL)%M;
                ans=ans%M;
            }
        }
        return dp[p]=ans;
    }    
    int numFactoredBinaryTrees(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            dp[i]=solve(i,arr);
            ans+=dp[i];
            ans=ans%M;
        }
        return ans;
    }
};
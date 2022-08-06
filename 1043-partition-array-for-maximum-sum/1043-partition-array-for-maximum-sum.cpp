class Solution {
public:
    #define ll long long 
    ll dp[505];
    ll solve(int i,int n,int k,vector<int> & arr){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        ll ans=0;
        ll maxele=0;
        for(int j=i;j<min(i+k,n);j++){
            maxele=max(maxele,1LL*arr[j]);
            ll siz=j-i+1;
            ll sumhere=maxele*siz+solve(j+1,n,k,arr);
            ans=max(ans,sumhere);
        }
        return dp[i]=ans;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,n,k,arr);
        return ans;
    }
};
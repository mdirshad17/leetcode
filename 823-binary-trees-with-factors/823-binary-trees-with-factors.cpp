class Solution {
public:
    #define ll long long 
    #define M 1000000007
    unordered_map<int,int> mp;
    ll dp[1005];
ll solve(int ind,vector<int> & arr){
        if(dp[ind]!=-1)return dp[ind];
        int ans=1;
        for(int i=0;i<arr.size();i++){
            if(arr[ind]%arr[i])continue;
            int l=arr[ind]/arr[i];
            if(mp.count(l)){
                ans+=((solve(i,arr)%M)*(solve(mp[l],arr)%M))%M;
            }
            ans=ans%M;
        }
        return dp[ind]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll ans=0;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<arr.size();i++){
            ans+=solve(i,arr);
            ans=ans%M;
        }
        return ans;
    }
};
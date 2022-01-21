class Solution {
public:
    #define ll long long
    #define M 1000000007
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]=arr[i]%2;
        }
        map<int,ll> mp;
        mp[0]=1;
        ll ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            sum=sum%2;
            int ss=(sum+1)%2;
            if(mp.count(ss)){
                ans+=mp[ss];
                ans=ans%M;
            }
            mp[sum]++;
        }
        return ans;
    }
};
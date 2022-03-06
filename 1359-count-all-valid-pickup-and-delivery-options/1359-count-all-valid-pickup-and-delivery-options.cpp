class Solution {
public:
    #define ll long long 
    #define M 1000000007
    int ns;
    ll dp[1005][505];
    ll solve(int num,int cnt){
        if(cnt<0)return 0;
        if(num==0){
            return (cnt==0);
        }
        if(dp[num][cnt]!=-1)return dp[num][cnt]%M;
        ll ans=0;
        ll op1=(cnt)*1LL*solve(num-1,cnt-1)%M;
        int pc=ns-cnt;
        int dc=(2*ns-num)-pc;
        int g=pc-dc;
        if(dc<pc){
            ans+=g*solve(num-1,cnt)%M;
        }
        return dp[num][cnt]=(ans+op1)%M;
    }
    int countOrders(int n) {
        ns=n;
        memset(dp,-1,sizeof(dp));
       return solve(2*n,n); 
    }
};
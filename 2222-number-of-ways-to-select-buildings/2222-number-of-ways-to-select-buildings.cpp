class Solution {
public:
    #define ll long long
    ll dp[100006][2][4];
    ll solve(int s,string & p,int f,int cnt){
        if(cnt>3)return 0;
        if(s>=p.size()){
            return (cnt==3);
        }
        if(dp[s][f][cnt]!=-1)return dp[s][f][cnt];
        ll op1=solve(s+1,p,f,cnt);
        ll op2=0;
        int num=(p[s]-'0');
        if((num^f)==1)op2=solve(s+1,p,(f^1),cnt+1);
        return dp[s][f][cnt]=op1+op2;
    }
    long long numberOfWays(string s) {
        memset(dp,-1,sizeof(dp));
        ll ans=solve(0,s,0,0)+solve(0,s,1,0);
        return ans;
    }
};
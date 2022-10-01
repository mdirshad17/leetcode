class Solution {
public:
    int dp[105];
    int solve(int i,int n,string & s){
        if(i>=n)return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int op1=solve(i+1,n,s);
        int op2=0;
        if(i+1<n){
            int numf=(s[i]-'0')*10+(s[i+1]-'0');
            if(numf<=26)op2=solve(i+2,n,s);
        }
        return dp[i]=op1+op2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return solve(0,n,s);
    }
};
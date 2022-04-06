class Solution {
public:
    int dp[1005][1005];
    int solve(int s1,int s2,string & s,string & p){
        if(s1>=s.size()||s2>=p.size()){
            return 0;
        }
        if(dp[s1][s2]!=-1)return dp[s1][s2];
        int op1=solve(s1+1,s2,s,p);
        int op2=solve(s1,s2+1,s,p);
        int ans=0;
        if(s[s1]==p[s2]){
            ans=1+solve(s1+1,s2+1,s,p);
        }
        return dp[s1][s2]=max({op1,op2,ans});
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string p=s;
        reverse(p.begin(),p.end());
        return solve(0,0,s,p);
    }
};
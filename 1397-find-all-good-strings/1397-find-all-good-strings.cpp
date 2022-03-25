class Solution {
public:
    #define ll long long 
    #define M 1000000007
    vector<int> lps;
    int dp[505][55][2][2];
    string ev;
    ll solve(int s,int n,int m,string & s1,string & s2,int c1,int c2){
        if(m>=ev.size())return 0;
        if(s>=n){
            return 1;
        }
        if(dp[s][m][c1][c2]!=-1)return (dp[s][m][c1][c2]%M);
        char left=c1?s1[s]:'a';
        char right=c2?s2[s]:'z';
        ll ans=0;
        for(char i=left;i<=right;i++){
            int j=m;
            while(j>0 && i!=ev[j]){
                j=lps[j-1];
            }
            if(ev[j]==i)j++;
            ans+=(solve(s+1,n,j,s1,s2,(c1&&(i==s1[s])),(c2&&(i==s2[s])))%M);
            ans=ans%M;
        }
        return dp[s][m][c1][c2]=ans%M;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        memset(dp,-1,sizeof(dp));
        int m=evil.size();
         ev=evil;
        int j=0;
        lps.resize(m);
        lps[0]=0;
        for(int i=1;i<m;i++){
            j=lps[i-1];
            while(j>0 && evil[i]!=evil[j]){
                j=lps[j-1];
            }
            if(evil[i]==evil[j])j++;
            lps[i]=j;
        }
        return solve(0,n,0,s1,s2,1,1);
        
    }
};
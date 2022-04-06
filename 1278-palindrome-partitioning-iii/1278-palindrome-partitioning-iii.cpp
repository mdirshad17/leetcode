class Solution {
public:
    int dp[105][105];
    int dpp[105][105];
    int solve(int s,int n,string & p,int k){
        if(s>=n){
            if(k==0)return 0;
            return INT_MAX/10;
        }
        if(k<0)return INT_MAX/10;
        if(dpp[s][k]!=-1)return dpp[s][k];
        int ans=INT_MAX/10;
        for(int i=s;i<n;i++){
            int l=dp[s][i]+solve(i+1,n,p,k-1);
            ans=min(ans,l);
        }
        return dpp[s][k]=ans;
    }
    int palindromePartition(string s, int k) {
        int n=s.size();
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)dp[i][j]=0;
                else if(g==1){
                    dp[i][j]=(s[i]!=s[j]);
                }else{
                    dp[i][j]=(s[i]!=s[j])+dp[i+1][j-1];
                }
            }
        }
        memset(dpp,-1,sizeof(dpp));
        return solve(0,n,s,k);
    }
};
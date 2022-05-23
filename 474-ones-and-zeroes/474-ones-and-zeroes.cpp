class Solution {
public:
    int dp[605][105][105];
    int solve(int s,int ni,vector<int> & a,vector<int> & b,int m,int n){
        if(m<0||n<0){
            return INT_MIN/10;
        }
        if(s>=ni){
            return 0;
        }
        if(dp[s][m][n]!=-1)return dp[s][m][n];
        int op1=solve(s+1,ni,a,b,m,n);
        int op2=1+solve(s+1,ni,a,b,m-b[s],n-a[s]);
        return dp[s][m][n]=max(op1,op2);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        
        memset(dp,-1,sizeof(dp));
        int ni=s.size();
        vector<int> a(ni,0);
        vector<int> b(ni,0);
        for(int i=0;i<ni;i++){
            for(char x:s[i]){
                a[i]+=(x=='1');
                b[i]+=(x=='0');
            }
        }
        return solve(0,a.size(),a,b,m,n);
    }
};
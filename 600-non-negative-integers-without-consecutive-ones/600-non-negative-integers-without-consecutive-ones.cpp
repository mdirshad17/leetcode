class Solution {
public:
    vector<int> v;
    int dp[40][2][2];
    int solve(int s,int n,int c,int p){
        if(s>=n){
            return 1;
        }
        if(dp[s][c][p]!=-1)return dp[s][c][p];
        int ans=0;
        if(c==0){
            ans+=solve(s+1,n,c,0);
            if(p==0)ans+=solve(s+1,n,c,1);
        }else {
            for(int i=0;i<=v[s];i++){
                if(i==1){
                    if(p==0)ans+=solve(s+1,n,(i==v[s]),i);
                }else{
                    ans+=solve(s+1,n,(i==v[s]),i);
                }
            }
        }
        return dp[s][c][p]=ans;
        
    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        // vector<int> v;
        while(n){
            v.push_back((n%2));
            n=n/2;
        }
        reverse(v.begin(),v.end());
        return solve(0,v.size(),1,0);
    }
};
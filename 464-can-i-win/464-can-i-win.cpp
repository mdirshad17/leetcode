
class Solution {
public:
    int dp[2097152]; 
    int solve(int mask,int m,int d){
        
        int sum=0;
        for(int i=1;i<=m;i++){
            
            if((mask&(1<<i))){
                sum+=i;
            }
        }
        if(sum>=d)return 0;
        if(dp[mask]!=-1)return dp[mask];
        int ans=0;
        for(int i=1;i<=m;i++){
            
            if((mask&(1<<i))==0){
                int l=solve((mask|1<<i),m,d);
                if(l==0){
                    return dp[mask]=1;
                }
            }
        }
        return dp[mask]=0;
    }
    bool canIWin(int ma, int d) {
        // dp[300][1000000]
        // Tc 300*10^6*20
        // (20*21)/10=210 211
        int sum=ma*(ma+1);
        sum=sum/2;
        cout<<sum<<" "<<d<<endl;
        if(sum<d)return 0;
        if(d==0){
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        // mask,maxchoosable desired
       return solve(0,ma,d);
    }
};
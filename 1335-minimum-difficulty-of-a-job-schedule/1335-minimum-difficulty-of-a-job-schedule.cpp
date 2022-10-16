class Solution {
public:
    int dp[320][12];
    int solve(int s,int n,vector<int> & job,int d){
        if(s>=n)
        {
            if(d==0)
            {
                return 0;
            }
            return 500000;
        }
        if(d<=0)
        {
            return 500000;
        }
         if(dp[s][d]!=-1)
         {
             return dp[s][d];
         }
        int ans=500000;
        int maxi=0;
        for(int i=s;i<n;i++)
        {
            maxi=max(maxi,job[i]);
            
            int f=maxi+solve(i+1,n,job,d-1);
            
            ans=min(ans,f);
        }
        // cout<<ans<<" "<<s<<endl;
        return dp[s][d]=ans;
    }
    int minDifficulty(vector<int>& job, int d) 
    {
        memset(dp,-1,sizeof(dp));
        int n=job.size();
      int f=solve(0,n,job,d);
        return (f>=500000)?-1:f;
    }
};
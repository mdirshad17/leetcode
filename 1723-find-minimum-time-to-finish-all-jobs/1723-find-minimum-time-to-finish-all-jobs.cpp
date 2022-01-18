class Solution {
public:
    int MASK;
    vector<int> dp[13];
    int sumd[4098];
    void get(vector<int> & v){
        
        for(int j=1;j<=MASK;j++){ 
            int sum=0;
        for(int i=0;i<v.size();i++){
            if(((1<<i)&j))sum+=v[i];
        }
            sumd[j]=sum;
    }
        // return sum;
    }
    int solve(int k,vector<int> & v,int mask){
        if(k==0){
            if(mask==MASK)return 0;
            return INT_MAX;
        }
        if(dp[k][mask]!=-1) return dp[k][mask];
        int ans=INT_MAX;
        for(int i=1;i<=MASK;i++){
            if(i&mask)continue;
            int sums=sumd[i];
            if(sums<=ans){
            sums=max(sums,solve(k-1,v,(mask|i)));
             ans=min(ans,sums);   
            }
           
        }
        return dp[k][mask]=ans;
        
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // memset(dp,-1,sizeof(dp));
        int n=jobs.size();
        MASK=(1LL<<n)-1;
        for(int i=0;i<13;i++) dp[i].assign(MASK+10,-1);
        get(jobs);
        return solve(k,jobs,0);
    }
};
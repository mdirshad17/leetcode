class Solution {
public:
    int getbs(vector<vector<int> > & V,int i,int j){
        int l=i+1,r=j;
        int ans=0;
        while(l<=r){
            int m=(l+r)/2;
            if(V[i][1]<=V[m][0]){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {
         vector<vector<int>> V;
         int n=S.size();
         for(int i=0;i<n;i++){
             V.push_back({S[i],E[i],P[i]});
         }
        sort(V.begin(),V.end());
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        int smax[n+1];
        memset(smax,0,sizeof(smax));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int idx=getbs(V,i,n-1);
            dp[i]=smax[idx]+V[i][2];
            smax[i]=max(smax[i+1],dp[i]);
        }
        return smax[0];
    }
};
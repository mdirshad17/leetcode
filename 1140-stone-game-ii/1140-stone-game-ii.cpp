class Solution {
public:
    int dp[205][205];
    int solve(int s,int n,vector<int> & piles,int m){
        if(s>=n)return 0;
        if(dp[s][m]!=INT_MIN)return dp[s][m];
        int ans=INT_MIN/10;
        int sum=0;
        for(int i=1;(i<=2*m && s+i<=n);i++){
            sum+=piles[(s+i-1)];
            int l=sum-solve(s+i,n,piles,max(m,i));
            ans=max(ans,l);
        }
        return dp[s][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
     for(int i=0;i<205;i++){
         for(int j=0;j<205;j++){
             dp[i][j]=INT_MIN;
         }
     }
      int n=piles.size();  
      int ans=solve(0,n,piles,1); 
        
      for(int x:piles)ans+=x;
        
        
        return ans/2;
        
    }
};
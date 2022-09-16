class Solution {
public:
    int n;
    int dp[1010][1010];
    int solve(int i,int l,int m,vector<int> & v,vector<int> & M){
      if(i>=m)return 0;
      if(dp[i][l]!=INT_MIN)return dp[i][l];  
      int leftmoves=l;
      int rightmoves=i-l;  
      int r=n-1-rightmoves;
      int op1=v[l]*M[i]+solve(i+1,l+1,m,v,M);
      int op2=v[r]*M[i]+solve(i+1,l,m,v,M);
      return dp[i][l]=max(op1,op2);  
        
    }
    int maximumScore(vector<int>& nums, vector<int> &M) {
       n=nums.size(); 
       int m=M.size(); 
       for(int i=0;i<1010;i++){
           for(int j=0;j<1010;j++){
               dp[i][j]=INT_MIN;
           }
       } 
       int ans=solve(0,0,m,nums,M);
       return ans; 
    }
};
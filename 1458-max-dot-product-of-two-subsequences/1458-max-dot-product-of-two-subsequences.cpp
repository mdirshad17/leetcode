class Solution {
public:
    int dp[502][502][2];
    int solve(int s1,int s2,vector<int> & a,vector<int>&b,int f){
        if(s1>=a.size()||s2>=b.size()){
            if(f)return 0;
            return INT_MIN/10;
        }
        if(dp[s1][s2][f]!=-1)return dp[s1][s2][f];
        int op1=solve(s1+1,s2,a,b,f);
        int op2=solve(s1,s2+1,a,b,f);
        int op3=a[s1]*b[s2]+solve(s1+1,s2+1,a,b,1);
        return dp[s1][s2][f]=max({op1,op2,op3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2,0);
    }
};
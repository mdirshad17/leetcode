class Solution {
public:
    #define ll long long 
    #define M 1000000007
    vector<int> nums;
    int dp[1005][250];
    int goodArr[250][250];
    int PW;
    void getOs(int m,int p,int num){
        if(m==0){
            nums.push_back(num);
           return;     
        }
        for(int i=0;i<=2;i++){
            if(i==p)continue;
            getOs(m-1,i,(num*3)+i);
        }
    }
    int good(int a,int b,int m){
        if(a==-1) return 1;
        int pw=PW;
        for(int i=0;i<m;i++){
            // cout<<a<<" "<<b<<" "<<pw<<"\n";
            int an=a/pw;
            int bn=b/pw;
            if(an==bn) return 0;
            a=a%pw;
            b=b%pw;
            pw=pw/3;
        }
        return 1;
    }
    int goo(int a,int b){
        if(a<0) return 1;
        return goodArr[a][b];
    }
    int solve(int i,int n,int p,int m){
        if(i>=n) return 1;
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        ll ans=0;
        for(int j=0;j<nums.size();j++){
            if(goo(p,nums[j])){
                ans+=solve(i+1,n,nums[j],m);
                ans=ans%M;
            }
        }
        ans=ans%M;
        return dp[i][p+1]=ans;
    }
    int colorTheGrid(int m, int n) {
         getOs(m,-1,0);
         PW=1;
         for(int i=1;i<m;i++){
            PW*=3;
         }
         memset(dp,-1,sizeof(dp));
         for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                goodArr[nums[i]][nums[j]]=good(nums[i],nums[j],m);
            }
         }
        //  for(int x:nums){
        //     cout<<x<<" ";
        //  }
        //  cout<<"\n";
         return solve(0,n,-1,m);
        //  return 0;
    }
};
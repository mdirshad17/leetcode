class Solution {
public:
    int MASK;
    int dp[50][32770];
    int solve(int s,int n,vector<string> & st,int mask,string & p){
        if(s>=n){
            if(MASK==mask)return 0;
            return INT_MAX/100;
        }
        if(dp[s][mask]!=-1)return dp[s][mask];
        int op1=solve(s+1,n,st,mask,p);
        int op2=INT_MAX/100;
        int nm=mask;
        int a[26]={0};
        for(int i=0;i<st[s].size();i++){
            a[st[s][i]-'a']++;
        }
        for(int i=0;i<p.size();i++){
            if((mask&(1<<i)))continue;
            if(a[p[i]-'a']){
                nm=nm|(1<<i);
                a[p[i]-'a']--;
            }
        }
        if(nm!=mask)op2=1+solve(s,n,st,nm,p);
        return dp[s][mask]=min(op1,op2);
    }
    int minStickers(vector<string>& s, string p) {
        
       memset(dp,-1,sizeof(dp)); 
       int n=p.size();
       MASK=(1<<n)-1;
         int f=solve(0,s.size(),s,0,p); 
          if(f>=INT_MAX/100)return -1;
          return f;
    }
};
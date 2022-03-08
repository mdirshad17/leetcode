class Solution {
public:
    int dp[65][65540];
    int solve(int s,int n,vector<vector<int> > & p,int mask,int rm){
        if(s>=n){
            if(mask==rm)return 0;
            return INT_MAX/100;
        }
        if(dp[s][rm]!=-1)return dp[s][rm];
        int op1=solve(s+1,n,p,mask,rm);
        int op2=INT_MAX/100;
        int mm=rm;
        for(auto x:p[s]){
            if(x==-1)continue;
            mm|=(1<<x);
        }
        op2=1+solve(s+1,n,p,mask,mm);
        return dp[s][rm]=min(op1,op2);
    }
    vector<int> res;
    void getpath(int s,int n,vector<vector<int> > & p,int mask,int rm){
        if(s>=n)return;
        
        int op1=solve(s+1,n,p,mask,rm);
        int op2=INT_MAX/100;
        int mm=rm;
        for(auto x:p[s]){
            if(x==-1)continue;
            mm|=(1<<x);
        }
        op2=1+solve(s+1,n,p,mask,mm);
        if(op1<=op2){
            getpath(s+1,n,p,mask,rm);
        }else{
            res.push_back(s);
            getpath(s+1,n,p,mask,mm);
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& r, vector<vector<string>>& p) {
        unordered_map<string,int> mp;
        memset(dp,-1,sizeof(dp));
        int n=r.size();
        int mask=0;
        for(int i=0;i<n;i++){
            mp[r[i]]=i;
            mask|=(1<<i);
        }
        vector<vector<int> > v(p.size());
        for(int i=0;i<p.size();i++){
            for(auto x:p[i]){
                if(mp.count(x)){
                    v[i].push_back(mp[x]);
                }else v[i].push_back(-1);
            }
        }
        solve(0,p.size(),v,mask,0);
        getpath(0,p.size(),v,mask,0);
         
        return res;
    }
};
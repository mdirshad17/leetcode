class Solution {
public:
    map<string,int> mp;
    int dp[305];
    int solve(int i,int n,string &s){
        // ......base case
        if(i>=n)return 1;
        if(dp[i]!=-1)return dp[i];
        // int ans=0;
        string g;
        for(int j=i;j<n;j++){
            g.push_back(s[j]);
            if(mp.count(g)){
                int l=solve(j+1,n,s);
                if(l==1)return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        memset(dp,-1,sizeof(dp));
        for(auto x:wordDict){
            mp[x]=1;
        }
        int n=s.size();
        int ans=solve(0,n,s);
        return ans;
        
    }
};
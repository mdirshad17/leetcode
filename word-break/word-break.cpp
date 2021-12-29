class Solution {
public:
    set<string> st;
    int dp[310];
    int solve(int s,int n,string & p){
        if(s>=n) return 1;
        if(dp[s]!=-1) return dp[s];
        string g;
        int ans=0;
        for(int i=s;i<n;i++){
            g.push_back(p[i]);
            if(st.count(g)){
                int f=solve(i+1,n,p);
                ans=ans|f;
            }
            
            if(ans) return dp[s]=1;
        } 
        return dp[s]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        memset(dp,-1,sizeof(dp));
       for(auto x:wordDict) st.insert(x); 
        int n=s.size();
       return solve(0,n,s);    
    }
};
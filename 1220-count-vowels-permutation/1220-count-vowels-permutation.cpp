class Solution {
public:
    #define ll long long
    #define M 1000000007
    ll dp[20005][6];
    string s="aeiou";
    map<char,string> mp;
    int getindex(char c){
        for(int i=0;i<s.size();i++){
            if(c==s[i])return i;
        }
        return 0;
    }
    ll solve(int i,int n,char c){
        if(i>=n)return 1;
        ll ans=0;
        if(dp[i][getindex(c)]!=-1)return dp[i][getindex(c)];
        for(char t:mp[c]){
            ans+=solve(i+1,n,t);
            ans=ans%M;
        }
        return dp[i][getindex(c)]=ans;
    }
    int countVowelPermutation(int n) {
        
        mp['a']="e";
        mp['e']="ai";
        mp['i']="aeou";
        mp['o']="iu";
        mp['u']="a";
        ll ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.size();i++){
            ans+=solve(1,n,s[i]);
            ans=ans%M;
        }
        return ans;
    }
};
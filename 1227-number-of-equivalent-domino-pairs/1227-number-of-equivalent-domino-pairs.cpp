class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int dp[10][10];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(auto x:dominoes){
            int u=x[0];
            int v=x[1];
            if(u>v){
                swap(u,v);
            }
            dp[u][v]++;
            ans+=(dp[u][v]-1);
        }
        return ans;
       
    }
};
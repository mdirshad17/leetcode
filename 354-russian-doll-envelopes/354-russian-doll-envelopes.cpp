class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](vector<int>& a,vector<int> & b){
           if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> dp;
        for(int i=0;i<env.size();i++){
            int height=env[i][1];
            auto idx=lower_bound(dp.begin(),dp.end(),height)-dp.begin();
            if(idx==dp.size())dp.push_back(height);
            else dp[idx]=height;
        }
        return dp.size();
    }
};
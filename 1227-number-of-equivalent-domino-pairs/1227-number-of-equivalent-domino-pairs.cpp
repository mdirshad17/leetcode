class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        for(auto x:dominoes){
            int u=x[0];
            int v=x[1];
            if(u>v){
                swap(u,v);
            }
            mp[{u,v}]++;

        }
        int ans=0;
        for(auto x:mp){
            int cnt=x.second;
            ans+=(cnt*(cnt-1))/2;
        }
        return ans;
    }
};
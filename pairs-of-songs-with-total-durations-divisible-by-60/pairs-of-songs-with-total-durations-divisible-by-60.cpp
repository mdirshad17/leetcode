class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int n=time.size();
        int ans=0;
        for(int i=0;i<n;i++){
            time[i]=time[i]%60;
            int l=(60-time[i])%60;
            ans+=(mp.count(l)?mp[l]:0);
            mp[time[i]]++;
        }
        return ans;
        
    }
};
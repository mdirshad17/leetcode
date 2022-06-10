class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int n=s.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp.size()<(i-j+1)){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                }
                j++;
            }
            int len=(i-j+1);
            ans=max(ans,len);
        }
        return ans;
    }
};
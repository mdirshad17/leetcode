class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k) return 0;
         map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(mp.size()){
            auto it=mp.begin();
            int val=(*it).first;
            mp[val]--;
            if(mp[val]==0){
                mp.erase(val);
            }
            for(int i=val+1;i<=val+k-1;i++){
                if(!mp.count(i)) return 0;
                 mp[i]--;
            if(mp[i]==0){
                mp.erase(i);
            }
            } 
        }
        return 1;
    }
};
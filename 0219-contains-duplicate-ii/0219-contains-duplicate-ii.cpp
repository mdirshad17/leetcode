class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                int idx=i-mp[nums[i]];
                if(idx<=k)return 1;
            }
            mp[nums[i]]=i;
        }
        return 0;
    }
};
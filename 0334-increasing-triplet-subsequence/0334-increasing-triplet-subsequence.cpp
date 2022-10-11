class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(); 
        int left[n];
        left[0]=INT_MAX;
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],nums[i-1]);
        }
        int maxel=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(left[i]<nums[i] && nums[i]<maxel)return 1;
            maxel=max(maxel,nums[i]);
        }
        return 0;
    }
};
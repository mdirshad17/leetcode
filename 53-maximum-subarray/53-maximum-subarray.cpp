class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int minel=0;
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum-minel);
            minel=min(minel,sum);
        }
        return ans;
        
    }
};
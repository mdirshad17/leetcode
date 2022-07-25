class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                ans[0]=m;
                r=m-1;
            }else if(nums[m]>target){
                r=m-1;
            }else l=m+1;
        }
        l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                ans[1]=m;
                l=m+1;
            }else if(nums[m]>target){
                r=m-1;
            }else l=m+1;
        }
        return ans;
    }
};
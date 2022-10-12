class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=2;i<n;i++){
            int s1=nums[i];
            int s2=nums[i-1];
            int s3=nums[i-2];
            if(((s3+s2)>s1) && ((s1-s2)<s3)){
                ans=max(ans,s1+s2+s3);
            }
        }
        return ans;
    }
};
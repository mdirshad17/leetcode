class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=2;i<n;i++){
            int diff=nums[i]-nums[i-1];
            for(int j=i-2;j>=0;j--){
                int diffx=nums[j+1]-nums[j];
                if(diffx==diff){
                    ans++;
                }else break;
            }
        }
        return ans;
    }
};
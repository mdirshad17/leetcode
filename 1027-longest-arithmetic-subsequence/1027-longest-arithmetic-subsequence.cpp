class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int d=-500;d<=500;d++){
            int num[505];
            memset(num,0,sizeof(num));
            for(int i=0;i<n;i++){
                int ns=nums[i]+d;
                if(ns>=0 && ns<=500){
                    num[nums[i]]=max(num[nums[i]],1+num[ns]);
                    ans=max(ans,num[nums[i]]);
                }else {
                    num[nums[i]]=max(num[nums[i]],1);
                     ans=max(ans,num[nums[i]]);
                }
            }
        }
        return ans;
    }
};
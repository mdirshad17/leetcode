class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<int> seq;
            int ans=1;
            seq.push_back(nums[0]);
            for(int i=1;i<n;i++){
                if(nums[i]>seq.back()){
                    seq.push_back(nums[i]);
                }else{
                    auto index=lower_bound(seq.begin(),seq.end(),nums[i])-seq.begin();
                    seq[index]=nums[i];
                }
            }
        return seq.size();
    }
};
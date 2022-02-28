class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n && (nums[j]==nums[j-1]+1)){
                j++;
            }
            if(i+1==j){
                res.push_back(to_string(nums[i]));
            }else{
                res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
            }
            i=j;
        }
        return res;
    }
};
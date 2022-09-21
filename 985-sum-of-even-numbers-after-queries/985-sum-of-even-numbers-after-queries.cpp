class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& Q) {
        
        int sum=0;
        vector<int> res;
        for(int x:nums){
            if(x&1)continue;
            sum+=x;
        }
        for(auto x:Q){
            int idx=x[1];
            int prev=nums[idx];
            nums[idx]+=x[0];
            if((prev&1)==0){
                sum-=prev;
            }
            if((nums[idx]%2)==0){
                sum+=nums[idx];
            }
            res.push_back(sum);
        }
        return res;
    }
};
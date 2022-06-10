class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            int search=-nums[i];
            while(j<k){
                
                int sum=nums[j]+nums[k];
                if(sum==search){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j+1<n && nums[j+1]==nums[j]){
                        j++;
                    }
                    while(k-1>=0 && nums[k-1]==nums[k]){
                        k--;
                    }
                    k--;
                    j++;
                }else if(sum>search){
                    k--;
                }else j++;
            }
        }
        return res;
        
    }
};
class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    void solve(int s,int n,vector<int> & nums){
        if(s>=n){
            res.push_back(v);
            return;
        }
        solve(s+1,n,nums);
        v.push_back(nums[s]);
        solve(s+1,n,nums);
        v.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums.size(),nums);
        return res;
    }
    
};
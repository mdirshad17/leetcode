class Solution {
public:
    vector<vector<int> > res;
    set<vector<int> > st;
    void solve(int l,int r,vector<int> & nums){
        if(l>r){
           if(!st.count(nums)){ 
           res.push_back(nums);
            st.insert(nums);   
           }
            return;
        }
        for(int i=l;i<=r;i++){
            
            swap(nums[i],nums[l]);
            solve(l+1,r,nums);
            swap(nums[i],nums[l]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    
        int n=nums.size();
        solve(0,n-1,nums);
        return res;
    }
};
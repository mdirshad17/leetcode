class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
       int n=nums.size();
        k=k%n;
        int l=(n-k);
        int l1=l-1;
        int r=n-1;
        while(l<r){
         swap(nums[l],nums[r]);
            l++;
            r--;
        }r=l1;
        l=0;
        while(l<r)
        {
         swap(nums[l],nums[r]);
            l++;
            r--;   
        }
        l=0,r=n-1;
        while(l<r)
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};
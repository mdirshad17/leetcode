class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> a=nums;
        sort(a.begin(),a.end());
        int li=0;
        while(li<n && nums[li]==a[li]){
            li++;
        }
        int ri=n-1;
        while(ri>=0 && nums[ri]==a[ri]){
            ri--;
        }
        int len=max(0,ri-li+1);
        return len;
        
    }
};
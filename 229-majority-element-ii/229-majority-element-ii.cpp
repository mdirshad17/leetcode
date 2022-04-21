class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)return {nums[0]};
    
        if(n==2){
            if(nums[0]==nums[1])return {nums[0]};
            return nums;
        }
        int num1=INT_MIN;
        int num2=INT_MIN;
        
        int cnt1=0,cnt2=0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==num1){
                cnt1++;
            }else if(nums[i]==num2){
                cnt2++;
            }else if(cnt1==0){
                cnt1=1;
                num1=nums[i];
            }else if(cnt2==0){
                cnt2=1;
                num2=nums[i];
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==num1){
                cnt1++;
            }
            if(nums[i]==num2){
                cnt2++;
            }
        }
        vector<int> res;
        if(cnt1>n/3){
            res.push_back(num1);
        }
        if(cnt2>n/3){
            res.push_back(num2);
        }
        return res;
    }
};
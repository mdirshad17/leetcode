class Solution {
public:
    #define ll long long 
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        // cout<<"Size of the array "<<n<<endl;
        ll sum=k;
        sum=(sum*(sum+1))/2;
        int s=k+1;
        ll diff=0;
        for(int i=0;i<n;i++){
           if(i>0 && nums[i]==nums[i-1])continue;
            if(nums[i]<s){
                sum-=nums[i];
                sum+=s;
                s++;
            }
          
        }
        return sum;
        
    }
};
class Solution {
public:
    #define ll long long
    int cnt=0;
    void m(vector<int> & a,vector<int> & b,vector<int> & nums){
        int i=0,j=0,k=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m){
           if(a[i]>(2LL*b[j])){
               cnt+=(n-i);
               j++;
           }else i++;
        }
        
        i=0,j=0;
        // int k=0;
        while(i<n && j<m){
           if(b[j]>a[i]){
               nums[k++]=a[i++];
           }else {
               nums[k++]=b[j++];
           }
        }
        while(j<m){
             nums[k++]=b[j++];
        }
        while(i<n){
             nums[k++]=a[i++];
        }
     
        
        
        
    }
    int ms(vector<int> & nums){
        int n=nums.size();
        if(n<=1)return 0;
        int n1=n/2;
       
        vector<int> v1,v2;
        for(int i=0;i<n1;i++){
            v1.push_back(nums[i]);
        }
        for(int i=n1;i<n;i++){
            v2.push_back(nums[i]);
        }
        ms(v1);
        ms(v2);
        m(v1,v2,nums);
        return 0;
        
    }
    int reversePairs(vector<int>& nums) {
        cnt=0;
         // nums= ms(nums);
        ms(nums);
        
        // for(int x:nums){
        //     cout<<x<<" ";
        // }cout<<endl;
        return cnt;
    }
};
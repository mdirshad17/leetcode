class Solution {
public:
    #define ll long long
    int cnt=0;
    vector<int> m(vector<int> & a,vector<int> & b){
        int i=0,j=0,k=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m){
           if(a[i]>(2LL*b[j])){
               cnt+=(n-i);
               j++;
           }else i++;
        }
        vector<int> res;
        i=0,j=0;
        while(i<n && j<m){
           if(b[j]>a[i]){
               res.push_back(a[i++]);
           }else {
               res.push_back(b[j++]);
           }
        }
        while(j<m){
            res.push_back(b[j++]);
        }
        while(i<n){
            res.push_back(a[i++]);
        }
        return res;
        
        
        
    }
    vector<int> ms(vector<int> & nums){
        int n=nums.size();
        if(n<=1)return nums;
        int n1=n/2;
       
        vector<int> v1,v2;
        for(int i=0;i<n1;i++){
            v1.push_back(nums[i]);
        }
        for(int i=n1;i<n;i++){
            v2.push_back(nums[i]);
        }
        v1=ms(v1);
        v2=ms(v2);
        return m(v1,v2);
        
    }
    int reversePairs(vector<int>& nums) {
        cnt=0;
         nums= ms(nums);
        
        // for(int x:nums){
        //     cout<<x<<" ";
        // }cout<<endl;
        return cnt;
    }
};
class Solution {
public:
    int good(int dist,vector<int> & v,int k){
        int j=0;
        int n=v.size();
        int cnt=0;
       for(int i=0;i<n;i++){
            while(j<n && (v[j]-v[i])<=dist){
                j++;
            }
           // cout<<i<<" "<<j<<" "<<endl;
           cnt+=(j-i)-1;
          
       } 
        // cout<<endl;
        return (cnt>=k);
       
    }
    int smallestDistancePair(vector<int>& nums, int k) 
    {
       sort(nums.begin(),nums.end());
       int l=0,r=INT_MAX/100;
       int ans=0; 
       while(l<=r){
           int m=(l+r)/2;
           if(good(m,nums,k)){
               // cout<<m<<" ";
               // cout<<"HELLO WORLD\n";
               ans=m;
               r=m-1;
           }else l=m+1;
       }
        return ans;
    }
};
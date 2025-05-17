class Solution {
public:
    #define ll long long 
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long diff=0;
        int n=nums1.size();
        int cntx=0,cnty=0;
        ll sum1=0;
        ll sum2=0;
        for(int i=0;i<n;i++){
            diff+=nums1[i];
            sum1+=nums1[i];
            cntx+=(nums1[i]==0);
        }
        n=nums2.size();
        for(int i=0;i<n;i++){
            diff-=nums2[i];
            cnty+=(nums2[i]==0);
            sum2+=nums2[i];
        }
        if(cntx==0 && cnty==0){
            if(sum1==sum2) return sum1;
        }else
        // diff>0
        // diff==0;
        // diff<0;
        if(cntx && cnty){
            sum1=sum1+cntx;
            sum2=sum2+cnty;
            return max(sum1,sum2);
        }else

        if(cntx==0){
            ll d=sum1-sum2;
            if(d>=cnty) return sum1;
        }else

        if(cnty==0){
            ll d=sum2-sum1;
            if(d>=cntx) return sum2;
        }
        return -1;




    }   
};
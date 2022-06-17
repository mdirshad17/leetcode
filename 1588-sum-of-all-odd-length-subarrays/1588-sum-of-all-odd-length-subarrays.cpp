class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int l1=i+1;
            int l2=(n-i);
            int lo=l1/2;
            int le=(l1+1)/2;
            int ro=(l2/2);
            int re=(l2+1)/2;
            ans+=((lo*ro)+(le*re))*arr[i];
        }
        return ans;
    }
};
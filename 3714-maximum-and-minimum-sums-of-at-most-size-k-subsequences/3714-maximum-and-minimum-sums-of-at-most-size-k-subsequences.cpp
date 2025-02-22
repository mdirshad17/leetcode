class Solution {
public:
    #define ll long long
    #define M 1000000007
    const static int N=1e5+10;
    int minMaxSums(vector<int>& nums, int k) {
       int ncr[N][75];
       ncr[0][0] = 1;
        for (int n = 1; n <N; n++) {
            ncr[n][0] = 1;
            for (int r = 1; r <= k; r++) 
                ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % M;
        } 
        ll sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=(2LL*nums[i]);
            sum=sum%M;
        }
        if(k==1) return sum;
        sort(nums.begin(),nums.end());
        for(int K=2;K<=k;K++){
        for(int i=K-1;i<n;i++){
             sum+=(nums[i]*1LL*ncr[i][K-1]);
             sum=sum%M;
             
        }
        }
        reverse(nums.begin(),nums.end());
        for(int K=2;K<=k;K++){
        for(int i=K-1;i<n;i++){
            sum+=(nums[i]*1LL*ncr[i][K-1]);
            sum=sum%M;
        }
        }
        return sum;
    }
};
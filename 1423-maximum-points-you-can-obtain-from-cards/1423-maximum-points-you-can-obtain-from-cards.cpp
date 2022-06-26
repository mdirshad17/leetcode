class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int sum=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        int wind=n-k;
        int ans=0;
        int rem=0;
        for(int i=0;i<wind;i++){
            rem+=v[i];
        }
        ans=max(ans,sum-rem);
        for(int i=wind;i<n;i++){
            rem+=v[i];
            rem-=v[i-wind];
            ans=max(ans,sum-rem);
        }
        return ans;
    }
};
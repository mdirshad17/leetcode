class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftm[n];
        int lm=0;
        for(int i=0;i<n;i++){
            lm=max(lm,height[i]);
            leftm[i]=lm;
        }
        int rm=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            rm=max(rm,height[i]);
            if(rm<=height[i]||leftm[i]<=height[i])continue;
            int L=min(rm,leftm[i]);
            ans+=L-height[i];
        }
        return ans;
    }
};
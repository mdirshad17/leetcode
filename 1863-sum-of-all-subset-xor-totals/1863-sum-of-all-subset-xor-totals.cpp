class Solution {
public:
    int pows[16];
    int subsetXORSum(vector<int>& nums) {
        pows[0]=1;
        for(int i=1;i<16;i++){
            pows[i]=pows[i-1]*2;
        }
        int n=nums.size();
        int cnt[7];
        memset(cnt,0,sizeof(cnt));
        for(int x:nums){
            for(int i=0;i<6;i++){
                cnt[i]+=(((1<<i)&x)>0);
            }
        }
        int ans=0;
        for(int i=0;i<6;i++){
            if(cnt[i]==0)continue;
            int l=pows[cnt[i]-1]*pows[n-cnt[i]]*(1<<i);
            ans+=l;
        }
        return ans;
    }
};
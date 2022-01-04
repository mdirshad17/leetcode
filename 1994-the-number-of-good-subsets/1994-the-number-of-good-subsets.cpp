
#define ll long long
#define M 1000000007
vector<ll> dp[1032];

ll pw[100005];
class Solution {
public:
    ll cnt[1032];
    vector<int> prs={2,3,5,7,11,13,17,19,23,29};
    vector<int> masks;
    ll solve(int s,int n,int mask){
        if(s>=n) return (mask!=0);
        if(dp[mask][s]!=-1) return (dp[mask][s])%M;
        ll op2=solve(s+1,n,mask)%M;
        ll op1=0;
        if((mask&masks[s])==0){
            ll num=(mask|masks[s]);
            op2+=((cnt[masks[s]]%M)*solve(s+1,n,(mask|masks[s]))%M)%M;
            op2=op2%M;
        }
        return  dp[mask][s]=op2%M;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        
        ll pr=1;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(num==1){
                pr=pr*2LL;
                pr=pr%M;
                continue;
            }
            int g=0;
            int maskf=0;
            for(int j=0;j<prs.size();j++){
                int cnt=0;
                while((num%prs[j])==0){
                    cnt++;
                    maskf=maskf|(1<<j);
                    num=num/prs[j];
                }
                if(cnt>1){
                    g=1;
                }
            }
            if(!g) cnt[maskf]++;
            if(!g && cnt[maskf]==1) masks.push_back(maskf);
        }
      
        int n=masks.size();
        for(int i=0;i<1032;i++)dp[i].assign(n+10,-1);
        ll f=(pr*solve(0,masks.size(),0))%M;
        return f;
        // return 0;
    }
};
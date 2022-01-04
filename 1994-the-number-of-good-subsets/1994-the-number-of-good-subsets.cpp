
// int dp[1032][100005;
 #define ll long long
    #define M 1000000007
vector<ll> dp[1032];

ll pw[100005];
class Solution {
public:
   
    void ppo(){
        if(pw[1])return;
        pw[0]=1;
        pw[1]=2;
        for(int i=2;i<100005;i++){
        pw[i]=(2LL*pw[i-1])%M;
        }
        for(int i=0;i<100005;i++){
         pw[i]=(pw[i]+M-1)%M;
        }
        
        
    }
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
            // if(nums[i]==14){
            //     cout<<maskf<<endl;
            // }
            if(!g) cnt[maskf]++;
            if(!g && cnt[maskf]==1) masks.push_back(maskf);
        }
        // cout<<nums.size()<<endl;
        int n=masks.size();
        
//         cout<<n<<endl;
//         for(int x:masks){
//             cout<<x<<" "<<cnt[x]<<endl;
//         }
        for(int i=0;i<1032;i++){
            dp[i].assign(n+10,-1);
        }
        ppo();
        // for(int i=0;i<masks.size();i++){
        //     cout<<masks[i]<<" ";
        // }cout<<endl;
        // return 0;
        // memset(dp,-1,sizeof(dp));
        ll f=(pr*solve(0,masks.size(),0))%M;
        return f;
        // return 0;
    }
};
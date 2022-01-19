class Solution {
public:
    int MASK;
    vector<int> v;
    int dp[16][65536];
    int getit(int n){
        if(n==0)return 0;
        return 1+getit(n-(n&(-n)));
    }
    void get(vector<int> & nums,int k){
        int n=nums.size();
        MASK=(1<<n)-1;
        int br=n/k;
        for(int i=1;i<=MASK;i++){
            int l=getit(i);
            if(l!=br)continue;
            int a[17]={0};
            for(int j=0;j<n;j++){
                if((i&(1<<j))){
                    a[nums[j]]++;
                }
            }
            int minel=INT_MAX;
            int maxel=INT_MIN;
            int g=0;
            for(int j=1;j<=16;j++){
                if(a[j]){
                    
                    minel=min(minel,j);
                    maxel=max(maxel,j);
                }
                if(a[j]>1){
                    
                    g=1;
                    break;
                }
            }
            if(g==0){
                // cout<<maxel<<" "<<minel<<" "<<i<<endl;
                v.push_back(i);
                 v.push_back(maxel-minel);
            }
        }
    }    
    int solve(int s,int n,int mask){
        if(s>=n){
            // cout<<mask<<" "<<MASK<<endl;
            if(mask==MASK)return 0;
            
            return INT_MAX/100;
        }
        if(dp[s][mask]!=-1)return dp[s][mask];
        int ans=INT_MAX/100;
        for(int i=0;i<v.size();i+=2){
            if((mask&v[i]))continue;
            
            int getsum=v[i+1];
            if(getsum<ans){
              ans=min(ans,getsum+solve(s+1,n,(mask|v[i])));
            }
        }
        return dp[s][mask]=ans;
        
    }
    int minimumIncompatibility(vector<int>& nums, int k) {
        if(k==16)return 0;
        sort(nums.begin(),nums.end());
        get(nums,k);
        memset(dp,-1,sizeof(dp));
        
        int l= solve(0,k,0);
        // cout<<l<<endl;
        if(l>1000)return -1;
        return l;
    }
};
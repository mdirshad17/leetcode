class Solution {
public:
    int MASK;
    int pre[1034];
    int dp[55][1034];
    void get(vector<int> & v){
        int n=v.size();
        for(int i=1;i<=MASK;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if((i&(1<<j))){
                    sum=sum+v[j];
                }
            }
            pre[i]=sum;
        }
    }
    int solve(int s,int n,vector<int> & v,vector<int> & q,int mask){
        if(s>=n){
           if(mask==MASK)return 1;
            
            return 0;
        }
        
        if(dp[s][mask]!=-1) return dp[s][mask];
        int op1=solve(s+1,n,v,q,mask);
        int ans=0;
        for(int i=1;i<=MASK;i++){
            if((mask&i))continue;
            int sum=pre[i];
            if(sum<=v[s]){
               //  cout<<"HELLO WORLD\n";
               // cout<<sum<<" "<<v[s]<<endl; 
               int op1=solve(s+1,n,v,q,(mask|i));
               if(op1){
                   ans=1;
                   break;
               } 
            }
            if(ans)break;
        }
        return dp[s][mask]=ans|op1;
    }
    bool canDistribute(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
         vector<int> v;
         int cnt=1;
         for(int i=1;i<nums.size();i++){
             if(nums[i]==nums[i-1]){
                 cnt++;
             }else{
                 v.push_back(cnt);
                 cnt=1;
             }
         }v.push_back(cnt);
         // for(int i:v){
         //     cout<<i<<" ";
         // }cout<<endl;
         int ns=q.size();
         MASK=(1<<ns)-1;
         get(q);
         // cout<<MASK<<endl;
         int f=solve(0,v.size(),v,q,0);
        return f;
        
    }
};
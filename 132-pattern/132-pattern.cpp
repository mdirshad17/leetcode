class Solution {
public:
    const static int N=2e5+10;
    int BIT[N];
    void add(int x, int val) {while (x < N)BIT[x] += val, x += x & -x;}
    int sum(int x) {return x ? BIT[x] + sum(x - (x & -x)) : 0;}
    bool find132pattern(vector<int>& nums) {
        map<int,int> mp;
            for(int x:nums) mp[x]=1;
        int si=1;
        for(auto & x:mp){
            x.second=si++;
        }
        int n=nums.size();
        int a[n];
        memset(a,0,sizeof(a));
        int pr=INT_MAX;
        for(int i=0;i<n;i++){
            a[i]=pr;
            nums[i]=mp[nums[i]];
            pr=min(pr,nums[i]);
            
        }
        add(nums[n-1],1);
        for(int i=n-2;i>=1;i--){
            int prm=a[i];
            int gr=nums[i];
            if(prm<gr){
                int cnt=sum(gr-1)-sum(prm);
                if(cnt)return 1;
            }
            add(gr,1);
        }
        return 0;
        
        
    }
};
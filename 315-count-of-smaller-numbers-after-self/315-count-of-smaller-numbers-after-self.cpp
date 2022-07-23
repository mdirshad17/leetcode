class Solution {
public:
    const static int N=1e5+10;
    int BIT[N];
    void add(int x,int val){
        while(x<N){
            BIT[x]+=val;
            x+=(x&(-x));
        }
    }
    int sum(int x){
        if(x==0)return 0;
        return BIT[x]+sum(x-(x&(-x)));
    }
    vector<int> countSmaller(vector<int>& nums) {
        for(int & x:nums){
            x+=(N/10);
        }
        int n=nums.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            res[i]=sum(nums[i]-1);
            add(nums[i],1);
        }
        return res;
        
    }
};
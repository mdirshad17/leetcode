class Solution {
public:
    #define ll long long 
    int ans=0;
    void solve(int s,int n,int pr,int num,ll sum){
        if(s>=n){
              // cout<<sum<<" "; 
            if(sum>num)return;
           
            if((num-ans)>(num-sum)){
                ans=sum;
            }
                return ;
        }
        for(int i=pr;i<=9;i++){
            solve(s+1,n,i,num,(sum*10LL+i));
        }
    }
    int monotoneIncreasingDigits(int n) {
        int dl=0;
        int num=n;
        while(n){
            n=n/10;
            dl++;
        }
        n=num;
        solve(0,dl,0,n,0);
        return ans;
    }
};
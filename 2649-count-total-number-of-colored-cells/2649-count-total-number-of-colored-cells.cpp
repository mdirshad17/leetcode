class Solution {
public:
    #define ll long long
    long long coloredCells(int n) {
        ll ans=(2*1LL*n)-1;
        for(int i=1;i<2*n-1;i+=2){
            ans+=(2*1LL*i);
        }
        return ans;
    }
};
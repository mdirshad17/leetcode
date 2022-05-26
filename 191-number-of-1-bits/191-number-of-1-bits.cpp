class Solution {
public:
    #define ll uint32_t
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            if((n&(1))){
                cnt++;
            }
            n=n/2;
        }
        return cnt;
    }
};
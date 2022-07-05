class Solution {
public:
    int hammingDistance(int x, int y) {
     
        int num=x^y;
        // find the number of set bits
        int cnt=0;
        while(num){
            cnt++;
            num-=(num&(-num));
        }
        return cnt;
        
    }
};
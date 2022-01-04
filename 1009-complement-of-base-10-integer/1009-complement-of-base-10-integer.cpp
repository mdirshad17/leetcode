class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int f=1;
        while(f<=n){
            f=f*2;
        }
        f=f-1;
        return f-n; 
    }
};
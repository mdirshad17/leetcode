class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        for(int i=0;i<f.size() && n;i++){
            if(f[i]==1)continue;
            int l=1;
            if(i-1>=0 && f[i-1]==1){
                l=0;
            }
            if(i+1<f.size() && f[i+1]==1){
                l=0;
            }
            n-=l;
            f[i]=l;
        }
        return n==0;
    }
};
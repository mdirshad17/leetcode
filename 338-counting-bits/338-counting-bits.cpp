class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)return {0};
        if(n==1)return {0,1};
        vector<int> res(n+1);
        res[0]=0;
        res[1]=1;
        int up=2;
        for(int i=2;i<=n;){
            
            for(int j=0;j<up && j+up<=n;j++){
                res[j+up]=1+res[j];
            }
            i=i+up;
            up=up*2;
        }
        return res;
    }
};
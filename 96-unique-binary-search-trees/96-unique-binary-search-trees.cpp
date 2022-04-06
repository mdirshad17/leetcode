class Solution {
public:
    int numTrees(int n) {
        int cn[n+1];
        memset(cn,0,sizeof(cn));
        cn[0]=1;
        cn[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                cn[i]+=cn[j]*cn[i-(j+1)];
            }
        }
        return cn[n];
    }
};
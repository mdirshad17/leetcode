class Solution {
public:
    int minCost(string c, vector<int>& N) {
        int n=c.size();
        int sum=N[0];
        int mc=N[0];
        for(int i=1;i<n;i++){
            if(c[i]==c[i-1]){
                sum+=N[i];
                mc=max(mc,N[i]);
            }else{
                sum-=mc;
                sum+=N[i];
                mc=N[i];
            }
        }
        sum-=mc;
        return sum;
        
    }
};
class Solution {
public:
    map<int,int> ld,rd;
    int cw[10];
    int safe(int r,int c){
        return (!rd[r+c] && !ld[r-c] && !cw[c]);
    }
    int solve(int r,int n){
        if(r>=n) return 1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(safe(r,i)){
                // unsafe it
                rd[r+i]=1;
                ld[r-i]=1;
                cw[i]=1;
                ans+=solve(r+1,n);
                // redo it
                rd[r+i]=0;
                ld[r-i]=0;
                cw[i]=0;
            }
        }
        
        
        return ans;
    }
    int totalNQueens(int n) 
    {
          int ans=solve(0,n);
        return ans;
    }
};
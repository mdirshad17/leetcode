class Solution {
    class cord{
        int x;
        int y;
        public cord(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
    cord pos[];
    boolean good(int x,int y){
        if(x==3 && y==0) return false;
        if(x==3 && y==2) return false;
        return true;
    }
    long dp[][][];
    int MOD=1000000007;
    int []dx={-2,-2,-1,-1,1,1,2,2};
    int []dy={-1,1,-2,2,-2,2,-1,1};
    int[] numbers = {1, 2, 3, 4, 5};
    long solve(int x,int y,int n){
        if(!good(x,y)){
            return 0;
        }
        if(n==0) return 1;
        if(dp[n][x][y]!=-1) return (int)dp[n][x][y];
        long ans=0;
        for(int j=0;j<8;j++){
            int X=x+dx[j];
            int Y=y+dy[j];
            if(X>=0 && Y>=0 && X<4 && Y<3){
                ans+=solve(X,Y,n-1);
                ans%=MOD;
            }    
        }
        return dp[n][x][y]=ans;
    }
    public int knightDialer(int n) {
        pos=new cord[12];
        int ci=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                pos[ci++]=new cord(i,j);
            }
        }
        dp=new long[n+2][5][4];
        for(int i=0;i<=n;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<4;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        long ans=0;
        for(int i=0;i<ci;i++){
            ans+=solve(pos[i].x,pos[i].y,n-1);
            ans%=MOD;
        }
        return (int)ans;

    }
}
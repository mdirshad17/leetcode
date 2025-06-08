class Solution {
    int dp[][];
    int solve(int i,int n,int[][] clips,int time,int ct){
        if(ct>=time) return 0;
        if(i>=n) return Integer.MAX_VALUE/1000;
        if(dp[i][ct]!=-1) return dp[i][ct];
        int ans=solve(i+1,n,clips,time,ct);
        if(ct>=clips[i][0]){
            ans=Math.min(ans,1+solve(i+1,n,clips,time,Math.max(ct,clips[i][1])));
        }
        return dp[i][ct]=ans;
    }
    public int videoStitching(int[][] clips, int time) {
        Arrays.sort(clips,(int [] a,int [] b)->{
            if(a[0]==b[0]) return a[1]-b[1];
            return a[0]-b[0];
        });
        dp=new int[105][105];
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                dp[i][j]=-1;
            }
        }
        int ans=solve(0,clips.length,clips,time,0);
        if(ans>101) return -1;
        return ans;
    }
}
class Solution {
    int dp[][];
    void getPath(int i,int n,String str1,int j,int m,String str2,StringBuilder sbr){
        if(i>=n) {
               for(int k=j;k<m;k++){
                  sbr.append(str2.charAt(k));
               }
                return;
        }
        if(j>=m) {
            for(int k=i;k<n;k++){
                  sbr.append(str1.charAt(k));
               }
            return;
        }
        
       // charAt
        int ans=Integer.MAX_VALUE/10;
        if(str1.charAt(i)==str2.charAt(j)){
            sbr.append(str1.charAt(i));
            ans=1+solve(i+1,n,str1,j+1,m,str2);
            getPath(i+1,n,str1,j+1,m,str2,sbr);
        }else{
             int op1=solve(i+1,n,str1,j,m,str2);
             int op2=solve(i,n,str1,j+1,m,str2);
             if(op1<=op2){
                sbr.append(str1.charAt(i));
                getPath(i+1,n,str1,j,m,str2,sbr);
             }else {
                sbr.append(str2.charAt(j));
                getPath(i,n,str1,j+1,m,str2,sbr);
            }
        }
        

    }
    int solve(int i,int n,String str1,int j,int m,String str2){
        if(i>=n) return (m-j);
        if(j>=m) return (n-i);
        if(dp[i][j]!=-1) return dp[i][j];
       // charAt
        int ans=Integer.MAX_VALUE/10;
        if(str1.charAt(i)==str2.charAt(j)){
            ans=1+solve(i+1,n,str1,j+1,m,str2);
        }else{
             int op1=solve(i+1,n,str1,j,m,str2);
             int op2=solve(i,n,str1,j+1,m,str2);
             ans=1+Math.min(op1,op2);
        }
        return dp[i][j]=ans;

    }
    public String shortestCommonSupersequence(String str1, String str2) {
        // str1[i] str2[j]=>put one
        // include str1[i] =>i+1,j
        // include str2[j]=>i,j+1
        // if (i>=n) add remaining j
        // if(j>=m) add remaining i
        int n=str1.length();
        int m=str2.length();
        dp=new int[n+2][m+2];
        for(int i=0;i<n+2;i++){
            for(int j=0;j<m+2;j++){
                dp[i][j]=-1;
            }
        }
        int len=solve(0,n,str1,0,m,str2);
        StringBuilder sbr=new StringBuilder();
        getPath(0,n,str1,0,m,str2,sbr);
        // System.out.println(len);
        return sbr.toString();
    }
}
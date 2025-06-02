class Solution {
    int dp[][];
    StringBuilder sbr;
    void getPath(int i,int[] digits,int sum ){
        if(i<=0){
            return;
        }
        int op1=1+solve(i-1,digits,((sum+digits[i-1])%3));
        int op2=solve(i-1,digits,sum);
        if(op1>=op2) {
            sbr.append((char)(digits[i-1]+'0'));
             getPath(i-1,digits,((sum+digits[i-1])%3));
        }else getPath(i-1,digits,sum);
    }
    int solve(int i,int[] digits,int sum){
        if(i<=0){
            if(sum==0) return 0;
            return Integer.MIN_VALUE/100;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int op1=1+solve(i-1,digits,((sum+digits[i-1])%3));
        int op2=solve(i-1,digits,sum);
        if(op1>=op2) return dp[i][sum]=op1;
        return dp[i][sum]=op2;
    }
    public String largestMultipleOfThree(int[] digits) {
        int n=digits.length;
        dp=new int[n+5][5];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        Arrays.sort(digits);
        sbr=new StringBuilder();
        int len=solve(n,digits,0);
        getPath(n,digits,0);
        int idx=0;
        while(sbr.length()>1 && sbr.charAt(0)=='0'){
            sbr.deleteCharAt(0);
        }
        System.out.println(len);
        return sbr.toString();
    }
}
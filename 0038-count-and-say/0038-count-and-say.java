class Solution {
    String solve(int n,String s){
        if(n==1) return s;
        int ns=s.length();
        StringBuilder sbr=new StringBuilder();
        int cnt=1;
        for(int i=1;i<ns;i++){
            if(s.charAt(i)==s.charAt(i-1)){
                cnt++;
            }else{
                sbr.append(String.valueOf(cnt));
                sbr.append(s.charAt(i-1));
                //sbr+=s.charAt(i-1);
                cnt=1;
            }
        }
        sbr.append(String.valueOf(cnt));
        sbr.append(s.charAt(ns-1));
        return solve(n-1,sbr.toString());


    }
    public String countAndSay(int n) {
        return solve(n,"1");
    }
}
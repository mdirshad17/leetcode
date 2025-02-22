class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1==s2) return true;
        int n=s1.length();
        int m=s2.length();
        if(n!=m) return false;
        int pr=-1;
        int cnt=0;
        boolean isdone=false;
        for(int i=0;i<n;i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                if(pr==-1){
                    pr=i;
                }else{
                   if(s1.charAt(i)==s2.charAt(pr) && s1.charAt(pr)==s2.charAt(i)){
                       isdone=true;
                   }     
                }
                cnt++;
            }
        }
    
    if(cnt==0) return true;
    if(cnt>2) return false;
    if(cnt==2) return isdone;
    return false;
    
    }

}
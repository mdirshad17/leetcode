class Solution {
    int vis[];
    boolean solve(int i,int n,String p,StringBuilder sb){
        if(i>=n) return true;
        System.out.println(sb);
        if(i==0){
            for(int j=1;j<=n;j++){
                sb.append((char)(j+'0'));
                vis[j]=1;
                if(solve(i+1,n,p,sb)){
                    return true;
                }
                vis[j]=0;
                sb.setLength(sb.length() - 1);
            }
        }else{
           int lastChar=Character.getNumericValue(sb.charAt(sb.length() - 1));
            if(p.charAt(i-1)=='D'){
                    for(int j=lastChar-1;j>=1;j--){
                        if(vis[j]==1)continue;
                        vis[j]=1;
                        sb.append((char)(j+'0'));
                    if(solve(i+1,n,p,sb)){
                        return true;
                    }
                    vis[j]=0;
                    sb.setLength(sb.length() - 1);
                    }
            }else{
                for(int j=lastChar+1;j<=n;j++){
                    if(vis[j]==1)continue;
                      vis[j]=1;
                      sb.append((char)(j+'0'));
                     if(solve(i+1,n,p,sb)){
                            return true;
                            }
                    vis[j]=0;
                    sb.setLength(sb.length() - 1);
                }
            }
        }

        return false;
    }
    public String smallestNumber(String p) {
     StringBuilder sbr=new StringBuilder("");
     int n=p.length();
     vis =new int[n+3];
     solve(0,n+1,p,sbr);
     return sbr.toString();
    }
}
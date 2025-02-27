class Solution {
    int col[];
    HashMap<Integer,Integer> tl;
    HashMap<Integer,Integer> tr;
    List<List<String>> res;
    boolean safe(int i,int j){
        if(col[j]==1) return false;
        if(tl.containsKey(i-j) && (tl.get(i-j)!=0)){
            return false;
        }
        if(tr.containsKey(i+j) && (tr.get(i+j)!=0)){
            return false;
        }

        return true;
    }
    void solve(int i,int n,char [][] board){
        if(i>=n) {
          res.add(getConstruct(board,n));
          return;
        }
        for(int j=0;j<n;j++){
            if(safe(i,j)){
                // place 
                col[j]=1;
                tl.put(i-j,1);
                tr.put(i+j,1);
                board[i][j]='Q';
                solve(i+1,n,board);
                tl.put(i-j,0);
                tr.put(i+j,0);
                col[j]=0;
                board[i][j]='.';
                // unplace it
            }
        }
        // return false;
    }
    public List<String> getConstruct(char[][] board,int n){
        List<String> resRowise=new ArrayList<>();
        for(int i=0;i<n;i++){
            String rowElement=new String(board[i]);
            resRowise.add(rowElement);
        }
        return resRowise;
    }
    public List<List<String>> solveNQueens(int n) {
        col=new int[n];
        tl=new HashMap<>();
        tr=new HashMap<>();
        res=new ArrayList<>();
        List<String> lst=new ArrayList<>();
        char[][] board=new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]='.';
            }
        }
        for(int i=0;i<n;i++){
            lst.add(new String(board[i]));
        }
        solve(0,n,board);
        // return res.add(new ArrayList<>(lst));
        return res;
    }
}
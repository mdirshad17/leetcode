class Solution {
    boolean good(int i,int j,int [][] grid,int n,int m){
        if(i+3>n||j+3>m){
            return false;
        }
        // System.out.println("this is  inside");
        int a[]=new int[10];
        Map<Integer,Integer> diag=new HashMap<>();
        Map<Integer,Integer> rdiag=new HashMap<>();
        int rowsum[]=new int[3];
        int colsum[]=new int[3];
        for(int ii=i;ii<i+3;ii++){
            for(int jj=j;jj<j+3;jj++){
                if(grid[ii][jj]<1||grid[ii][jj]>9) return false;
                diag.putIfAbsent(ii-jj,0);
                rdiag.putIfAbsent(ii+jj,0);
                diag.put(ii-jj,diag.get(ii-jj)+grid[ii][jj]);
                rdiag.put(ii+jj,rdiag.get(ii+jj)+grid[ii][jj]);
                a[grid[ii][jj]]++;
                rowsum[ii-i]+=grid[ii][jj];
                colsum[jj-j]+=grid[ii][jj];

            }
        }
        if(rowsum[0]!=rowsum[1] || rowsum[0]!=rowsum[2] || colsum[0]!=colsum[1] || colsum[1]!=colsum[2] || colsum[0]!=rowsum[0] ){
            return false;
        }
        for(int k=1;k<=9;k++){
            if(a[k]!=1){
                // System.out.println("This is "+a[k]);
                return false;
            }
        }
        int dsum=diag.get(i-j);
        int d1sum=rdiag.get(i+j+2);
        if(dsum!=d1sum||rowsum[0]!=dsum){
            return false;
        }
        return true;
    }
    public int numMagicSquaresInside(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(good(i,j,grid,n,m)){
                    ans++;
                }
            }
        }
        return ans;
    }
}
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long ans=0;
        List<Integer> lst=new ArrayList<>();
        List<Integer> lstNeg=new ArrayList<>();
        int n=matrix.length;
        int m=matrix[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]>=0){
                    lst.add(matrix[i][j]);
                }else {
                    lstNeg.add(matrix[i][j]);
                }
            }
        }
        Collections.sort(lst);
        Collections.sort(lstNeg);
        int len=lstNeg.size();
        int lenPos=lst.size();
        if((len%2)==1){
            if(lenPos>0){
                // 
                int maxNeg=lstNeg.get(len-1);
                int minPos=lst.get(0);
                if(Math.abs(maxNeg)>minPos){
                    lstNeg.set(len-1,lstNeg.get(len-1)*-1);
                    lst.set(0,lst.get(0)*-1);
                }
            }
            for(int i=0;i<len-1;i++){
                lstNeg.set(i,lstNeg.get(i)*-1);
            }
        }else{
            for(int i=0;i<len;i++){
                lstNeg.set(i,lstNeg.get(i)*-1);
            }
        }
        // long ans=0;
        for(int i=0;i<len;i++){
            ans+=(long)lstNeg.get(i);
        }

        for(int i=0;i<lenPos;i++){
            ans+=(long)lst.get(i);
        }
        return ans;

    }
}
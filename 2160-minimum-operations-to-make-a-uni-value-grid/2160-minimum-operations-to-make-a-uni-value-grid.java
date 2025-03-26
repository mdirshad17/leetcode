class Solution {
    public int minOperations(int[][] grid, int x) {
          int n=grid.length;
          int m=grid[0].length;
          int sz=n*m;
          int arr[]=new int[n*m];
          int k=0;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[k++]=grid[i][j];
            }
          }
          Arrays.sort(arr);
          int md=arr[((sz-1)/2)];
          int steps=0;
          for(int i=0;i<sz;i++){
            int diff=Math.abs(md-arr[i]);
            if((diff%x)!=0){
                steps=Integer.MAX_VALUE;
                break;
            }else steps+=(diff/x);
          }
          if((sz%2)==0){
                md=arr[((sz+1)/2)];
                int secondSteps=0;
            for(int i=0;i<sz;i++){
            int diff=Math.abs(md-arr[i]);
            if((diff%x)!=0){
                secondSteps=Integer.MAX_VALUE;
                break;
            }else secondSteps+=(diff/x);
          }
          steps=Math.min(steps,secondSteps);
          }

          if(steps==Integer.MAX_VALUE) return -1;
          return steps;



    }
}
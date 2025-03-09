class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n=colors.length;
        int ans=0;
        int sum=(k%2==0)?0:1;
        int runningSum=0;
        int newarr[]=new int[n];
        for(int i=0;i<n;i++){
            int idx=(i+1)%n;
            newarr[i]=(colors[i]!=colors[idx])?1:0;
        }
        k--;
        for(int i=0;i<k;i++){
           runningSum+=newarr[i];
        //    System.out.println(runningSum);
        }
        if(runningSum==k){
            ans++;
        }
        int j=k;
        for(int i=1;i<n;i++){
            runningSum+=newarr[j];
            runningSum-=newarr[i-1];
            System.out.println(runningSum);
            if(runningSum==k){
            ans++;
        }
            j=(j+1)%n;
        }
        return ans;
    }
}
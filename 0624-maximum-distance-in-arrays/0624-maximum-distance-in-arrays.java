class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        // int leftMax,rightMax;
        int n=arrays.size();
        int leftMax[]=new int[n];
        int rightMax[]=new int[n];
        Arrays.fill(leftMax,-100005);
        Arrays.fill(rightMax,-100005);
        for(int i=1;i<n;i++){
            leftMax[i]=Math.max(leftMax[i-1],arrays.get(i-1).get(arrays.get(i-1).size()-1));
        }
        for(int i=n-2;i>=0;i--){
            rightMax[i]=Math.max(rightMax[i+1],arrays.get(i+1).get(arrays.get(i+1).size()-1));
        }
        for(int i=0;i<n;i++){
            System.out.print(leftMax[i]+" ");
        }
        System.out.println();

        for(int i=0;i<n;i++){
            System.out.print(rightMax[i]+" ");
        }
        System.out.println();

       int ans=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int maxValue=-100005;
            // if((i-1)>=0){
                maxValue=Math.max(maxValue,leftMax[i]);
            // }
            // if(i<n){
               maxValue=Math.max(maxValue,rightMax[i]); 
            // }
            System.out.println(maxValue+" maxValue ");
            ans=Math.max(Math.abs(maxValue-arrays.get(i).get(0)),ans);
        }
        return ans;
    }
}
class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        
        int n=differences.length;
        long minVal=0;
        long maxVal=0;
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=differences[i];
            minVal=Math.min(minVal,sum);
            maxVal=Math.max(maxVal,sum);
        }
        long gt=upper-maxVal;
        long sm=lower-minVal;
        if(gt<sm) return 0;
        // System.out.print
        return (int)(gt-sm)+1;

        // x
        // x-40
    }
}
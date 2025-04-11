class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            String f=""+i;
            int len=f.length();
            if((len%2)==0){
                int sum=0;
                for(int j=0;j<len/2;j++){
                    sum+=(int)(f.charAt(j)-'0');
                }
                for(int j=len/2;j<len;j++){
                    sum-=(int)(f.charAt(j)-'0');
                }
                if(sum==0) ans++;
            }
        }
        return ans;
    }
}
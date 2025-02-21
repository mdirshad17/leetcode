class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int n=arr1.length;
        int m=arr2.length;
        
        int pos=1;
        int carry=0;
        int i=n-1;
        int j=m-1;
        List<Integer> ls=new ArrayList<Integer>();
        while(i>=0 && j>=0){
            int sumh=(arr1[i]+arr2[j]-carry);
            int digit=0;
            if(sumh<0){
                 digit=1;
                 carry=-1;   
            }else{
                digit=sumh%2;
                carry=sumh/2; 
            }
            ls.add(digit);
            pos=1-pos;
            i--;
            j--;
            // System.out.print(digit+" ");
        }
        while(i>=0){
            int sumh=(arr1[i]-carry);
            int digit=0;
             if(sumh<0){
                 digit=1;
                 carry=-1;   
            }else{
                digit=sumh%2;
                carry=sumh/2; 
            }
            ls.add(digit);
            pos=1-pos;
            i--;
            // System.out.print(digit+" ");
            // j++;
        }

        while(j>=0){
            int sumh=(arr2[j]-carry);
            int digit=0;
           if(sumh<0){
                 digit=1;
                 carry=-1;   
            }else{
                digit=sumh%2;
                carry=sumh/2; 
            }
            ls.add(digit);
            pos=1-pos;
            // i++;
            j--;
            // System.out.print(digit+" ");
        }
        System.out.print(carry+" ");
        if(carry!=0){
        ls.add(1);
        ls.add(1);
        
        }

    //    Collections.reverse(ls);
    // for(int k=0;k<ls.size();k++){
    //     System.out.print(ls.get(k)+" ");
    // }
    // cout<<"\n";

       while(ls.size()>1 && ls.get(ls.size()-1)==0){
        //  System.out.println("Hello");   
        ls.remove(ls.size()-1);
       }
    int sz=ls.size();
       int res[]=new int[sz];
     Collections.reverse(ls);
       for(int ii=0;ii<ls.size();ii++){
        res[ii]=ls.get(ii);
       }
    //    Arrays.reverse(res);
       return res;
    }
}
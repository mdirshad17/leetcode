class Solution {
    public String robotWithString(String s) {
        int arr[]=new int[26];
        int n=s.length();
        for(int i=0;i<n;i++){
            int ind=(int)(s.charAt(i)-'a');
            arr[ind]++;
        }
        int i=0;
        int j=0;
        StringBuilder res=new StringBuilder();
        StringBuilder t=new StringBuilder();
        while(i<26){
                char c=(char)(i+'a');
                while(t.length()>0 && t.charAt(t.length() - 1)<=c){
                        res.append(t.charAt(t.length() - 1));
                        t.deleteCharAt(t.length() - 1);
                }
            if(arr[i]==0){
                i++;
                continue;
            }
            if(j<n){
                while(j<n && arr[i]!=0){
                    int id=(int)(s.charAt(j)-'a');
                    if(id==i){
                        res.append(s.charAt(j));
                        arr[i]--;
                    }else{
                        t.append(s.charAt(j));
                        int ind=(int)(s.charAt(j)-'a');
                        arr[ind]--;
                    }
                    j++;
                }
            }
            i++;


        }
        while(t.length()>0){
            res.append(t.charAt(t.length()-1));
            t.deleteCharAt(t.length() - 1);
        }
        return res.toString();
        
    }
}
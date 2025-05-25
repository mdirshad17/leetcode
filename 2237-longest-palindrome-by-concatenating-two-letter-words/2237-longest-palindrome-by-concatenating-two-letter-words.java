class Solution {
    public int longestPalindrome(String[] words) {
        Map<String,Integer> mp=new HashMap<>();
        int n=words.length;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(words[i].charAt(0)==words[i].charAt(1)){
               if(mp.containsKey(words[i])){
                        mp.put(words[i],mp.get(words[i])+1);
                   }else mp.put(words[i],1);
            }else{
                StringBuilder sbr=new StringBuilder();
                sbr.append(words[i].charAt(1));
                 sbr.append(words[i].charAt(0));
                 String newF=sbr.toString();
                if(mp.containsKey(newF) && mp.get(newF)>=1){
                    cnt+=4;
                    mp.put(newF,mp.get(newF)-1);
                }else{
                   if(mp.containsKey(words[i])){
                        mp.put(words[i],mp.get(words[i])+1);
                   }else mp.put(words[i],1);
                }
            }
        }
        int odd=1;
        for (Map.Entry<String, Integer> entry : mp.entrySet()) {
            String key = entry.getKey();
            if(key.charAt(0)!=key.charAt(1)){
                continue;
            }
            Integer value = entry.getValue();
            if((value&1)!=0){
                if(odd==1){
                    cnt+=(2*value);
                    odd=0;
                }else{
                    cnt+=(2*(value-1));
                }
            }else cnt+=(2*value);

         
        }
        return cnt;
    }
}
class Solution {
    public String clearStars(String s) {
        Map<Integer,List<Integer>> mp=new HashMap<>();
        int n=s.length();
        StringBuilder sbr = new StringBuilder(s);
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='*'){
                boolean flag=true;
                for(int j=0;j<26;j++){
                    if(flag && mp.containsKey(j) && mp.get(j).size()>0){
                            int size=mp.get(j).size();
                            int idx=mp.get(j).get(size-1);
                            sbr.setCharAt(idx,'*');
                            mp.get(j).remove(size-1);
                            flag=false;
                            break;
                    }
                }
            }else{
                int val=(int)(s.charAt(i)-'a');
                mp.putIfAbsent(val,new ArrayList<>());
                mp.get(val).add(i);
            }
        }
        StringBuilder res=new StringBuilder();
        for (int i = 0; i < sbr.length(); i++) {
            char ch = sbr.charAt(i);
            if(ch!='*'){
                res.append(ch);
            }
        }
        return res.toString();
    }
}
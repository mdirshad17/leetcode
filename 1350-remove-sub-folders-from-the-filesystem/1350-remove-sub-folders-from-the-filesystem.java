class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Map<String,Integer> mp=new HashMap<String,Integer> ();
        int n=folder.length;
        Arrays.sort(folder,(a,b)->a.length()-b.length());
        for(int i=0;i<n;i++){
              StringBuilder sbr=new StringBuilder();  
            for(int j=0;j<folder[i].length();j++){
                    if(sbr.length()!=0 && folder[i].charAt(j)=='/' && mp.containsKey(sbr.toString())){
                        folder[i]="$";
                        break;
                    }
                    sbr.append(folder[i].charAt(j));
            }
            mp.put(folder[i],1);

        }
        List<String> res=new ArrayList<>();
        for(int i=0;i<n;i++){
            if(folder[i]=="$"){
                continue;
            }
            res.add(folder[i]);
        }
        return res;
    }
}
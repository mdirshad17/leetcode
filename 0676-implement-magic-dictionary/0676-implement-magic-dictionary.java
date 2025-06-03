class MagicDictionary {
    Map<String,Integer> mp;
    Map<String,Integer> inDict;
    public MagicDictionary() {
        mp=new HashMap<>();
        inDict=new HashMap<>();
    }
    
    void insert(String s){
        int cnt=0;
        if(mp.containsKey(s)){
           cnt= mp.get(s);
        }
        mp.put(s,cnt+1);
    }
    public void buildDict(String[] dictionary) {
        for(int i=0;i<dictionary.length;i++){
            String here=dictionary[i];
            inDict.put(here,1);
            int n=here.length();
            for(int j=0;j<n;j++){
                int len=j;
                StringBuilder sbr=new StringBuilder();
                if(len>0){
                    sbr.append(here.substring(0,j));
                }
                sbr.append('*');
                int postLen=n-(j+1);
                if(postLen>0){
                    sbr.append(here.substring(j+1));
                }
                insert(sbr.toString());  
            }

        }
    }

    void removeIt(String s){
        int n=s.length();
        for(int j=0;j<n;j++){
                int len=j;
                StringBuilder sbr=new StringBuilder();
                if(len>0){
                    sbr.append(s.substring(0,j));
                }
                sbr.append('*');
                int postLen=n-(j+1);
                if(postLen>0){
                    sbr.append(s.substring(j+1));
                }
                mp.put(sbr.toString(),mp.get(sbr.toString())-1);
            }
    }

    void insertIt(String s){
            int n=s.length();
        for(int j=0;j<n;j++){
                int len=j;
                StringBuilder sbr=new StringBuilder();
                if(len>0){
                    sbr.append(s.substring(0,j));
                }
                sbr.append('*');
                int postLen=n-(j+1);
                if(postLen>0){
                    sbr.append(s.substring(j+1));
                }
                mp.put(sbr.toString(),mp.get(sbr.toString())+1);
            }
    }
    
    public boolean search(String searchWord) {

            if(inDict.containsKey(searchWord)){
                removeIt(searchWord);
            }
            String here=searchWord;
            int n=here.length();
            boolean ans=false;
            for(int j=0;j<n;j++){
                int len=j;
                StringBuilder sbr=new StringBuilder();
                if(len>0){
                    sbr.append(here.substring(0,j));
                }
                sbr.append('*');
                int postLen=n-(j+1);
                if(postLen>0){
                    sbr.append(here.substring(j+1));
                }
                if(mp.containsKey(sbr.toString()) && mp.get(sbr.toString())>=1) {
                    ans=true;
                    break;
                }
            }
            if(inDict.containsKey(searchWord)){
                insertIt(searchWord);
            }
            return ans;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
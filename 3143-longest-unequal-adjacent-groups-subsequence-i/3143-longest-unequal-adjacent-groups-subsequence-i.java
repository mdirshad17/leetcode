class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> res1=new ArrayList<>();
        List<String> res2=new ArrayList<>();
        int n=words.length;
        int flag1=0,flag2=1;
        for(int i=0;i<n;i++){
            if(flag1==groups[i]){
                res1.add(words[i]);
                flag1^=1;
            }
            if(flag2==groups[i]){
                res2.add(words[i]);
                flag2^=1;
            }
        }
        if(res1.size()>=res2.size()) return res1;
        return res2;   
    }
}
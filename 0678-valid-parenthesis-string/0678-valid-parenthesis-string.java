class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> stOpen=new Stack<>();
        Stack<Integer> stClose=new Stack<>();
        Stack<Integer> wild=new Stack<>();
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)==')'){
                if(stOpen.isEmpty()){
                    if(wild.isEmpty()){
                        return false;
                    }else{
                        wild.pop();
                    }
                }else{
                    stOpen.pop();
                }
            }else if(s.charAt(i)=='('){
                    stOpen.add(i);
            }else{
                wild.add(i);
            }
        }
        if(stOpen.size()==0) return true;
        if(stOpen.size()>wild.size()) return false;
        while(stOpen.size()!=0){
            if(stOpen.peek()>wild.peek()){
                return false;
            }
            stOpen.pop();
            wild.pop();
        }
        return true;

    }
}
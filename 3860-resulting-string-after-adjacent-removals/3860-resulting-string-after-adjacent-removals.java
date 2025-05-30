class Solution {
    public String resultingString(String s) {
        Stack<Integer> st=new Stack<>();
        int n=s.length();
        for(int i=0;i<n;i++){
            int num=(int)(s.charAt(i)-'a');
            if(st.isEmpty()){
                
                st.push(num);
            }else {
                int prv=((num-1)+26)%26;
                int nxt=((num+1)%26);
                char here=(char)(prv+'a');
                char next=(char)(nxt+'a');
                if(st.peek()==prv||st.peek()==nxt){
                    st.pop();
                }else st.push(num);
            }
        }
        StringBuilder sbr=new StringBuilder();
        while(!st.isEmpty()){
           int peek=st.peek();
           st.pop();
           char her=(char)(peek+'a');
           sbr.append(her);
        }
        return sbr.reverse().toString();
    }
}
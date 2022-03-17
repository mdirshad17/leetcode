class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(-1);
            }else{
                if(st.top()>=0){
                    int num=st.top();
                    // cout<<num<<" ";
                    st.pop();
                    st.pop();
                    st.push(2*num);
                }else{
                    // cout<<st.top()<<" ";
                    st.pop();
                    st.push(1);
                }
                int num=0;
                while(st.size() && (st.top()!=-1)){
                    num+=st.top();
                    st.pop();
                }
                if(num!=0){
                    st.push(num);
                }
            }
        }
        return st.top();
    }
};
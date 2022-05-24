class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); 
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(st.size()>1){
                    st.pop();
                    
                    ans=max(ans,i-st.top());
                    // st.pop();
                }else{
                    while(st.size()){
                        st.pop();
                    }
                    st.push(i);
                }
            }else st.push(i);
        }
        return ans;
    }
};
class Solution {
public:
    string reverseParentheses(string s) 
    {
        string res;
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                st.push(s[i]);
            }else if(s[i]==')'){
                string g;
                while(st.size() && st.top()!='('){
                    g.push_back(st.top());
                    st.pop();
                }
                // reverse(g.begin(),g.end());
                st.pop();
                for(char x:g)st.push(x);
            }else st.push('(');
            
        }
        // string res;
        while(st.size()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
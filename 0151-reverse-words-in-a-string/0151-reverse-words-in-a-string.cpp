class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n=s.size();
        string F;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(F.size()){
                st.push(F);
                F.clear();}
            }else F.push_back(s[i]);
        }
        if(F.size()){
        st.push(F);}
        string res;
        while(st.size()){
            res+=(st.top())+' ';
            st.pop();
        }
        if(res.size()){
            res.pop_back();
        }
        
        return res;
    }
};
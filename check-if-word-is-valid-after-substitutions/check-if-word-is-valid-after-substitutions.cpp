class Solution {
public:
    
    bool isValid(string s) {
        int n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='c'){
                if(st.size()<2) return 0;
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(a!='a'||b!='b'){
                    return 0;
                }
            }else st.push(s[i]);
        }
        return (st.size()==0);
    }
};
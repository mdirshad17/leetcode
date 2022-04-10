class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string s:ops){
            if(s[0]=='C'){
                st.pop();
            }else if(s[0]=='D'){
                st.push(2*st.top());
            }else if(s[0]=='+') {
                int d=st.top();
                st.pop();
                int e=st.top();
                st.push(d);
                st.push(d+e);
            }else{
                int d=stoi(s);
                st.push(d);
            }
        }
        int ans=0;
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};
class Solution {
public:
    int evalRPN(vector<string>& s) 
    {
            int ans=0;
            stack<int> st;
         for(int i=0;i<s.size();i++){
             if(s[i]=="+"){
                 int num1=st.top();
                 st.pop();
                 num1+=st.top();
                 st.pop();
                 st.push(num1);
             }else if(s[i]=="-"){
                  int num1=st.top();
                 st.pop();
                 num1-=st.top();
                 num1=num1*-1;
                 st.pop();
                 st.push(num1);
             }else if(s[i]=="*"){
                  int num1=st.top();
                 st.pop();
                 num1*=st.top();
                 st.pop();
                 st.push(num1);
             }else if(s[i]=="/"){
                  int num1=st.top();
                 st.pop();
                 int num2=st.top();
                 st.pop();
                 st.push(num2/num1);
             }else{
                  st.push(stoi(s[i]));
             }
         }
        return st.top();
    }
};
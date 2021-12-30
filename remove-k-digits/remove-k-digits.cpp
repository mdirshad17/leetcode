class Solution {
public:
    string removeKdigits(string s, int k) 
    {
         stack<char> st;
         int n=s.size();
         for(int i=0;i<n;i++){
             while(st.size() && k && st.top()>s[i]){
                 st.pop();
                 k--;
             }
             st.push(s[i]);
         }
         while(st.size() && k){
             k--;
             st.pop();
         }
        if(st.size()==0) return "0";
        string ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>1 && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
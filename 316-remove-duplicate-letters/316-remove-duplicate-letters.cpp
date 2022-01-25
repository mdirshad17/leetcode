class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        int a[26]={0};
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        int k=0;
        for(int i=0;i<26;i++){
            k+=(a[i]>0);
        }
        int plc[26]={0};
        stack<int> st;
        for(int i=0;i<n;i++){
            while( st.size() && (st.top()>(s[i]-'a')) && (a[st.top()]>1) && plc[s[i]-'a']==0){
                a[st.top()]--;
                plc[st.top()]=0;
                st.pop();
            }
            if(plc[s[i]-'a']==0){
                 st.push((s[i]-'a'));
            }else {
                
                a[s[i]-'a']--;
            }
            plc[st.top()]=1;
            
        }
        stack<int> st1;
        while(st.size()){
            st1.push(st.top());
            st.pop();
        }
        memset(a,0,sizeof(a));
        string res;
         while(st1.size()){
            if(!a[st1.top()]){
                res.push_back('a'+st1.top());
            }
             a[st1.top()]=1;
             st1.pop();
        }
        return res;
        
    }
};
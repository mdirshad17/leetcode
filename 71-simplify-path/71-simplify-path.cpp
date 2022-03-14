class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        string s=path;
        int n=s.size();
        string g;
        
        for(int i=0;i<n;i++){
            if(s[i]=='/'){
               
               if(g==".."){
                   
                while(st.size() && st.top()!='/'){
                    st.pop();
                }   
                   if(st.size())st.pop();
                   while(st.size() && st.top()!='/'){
                    st.pop();
                }   
                   if(st.size())st.pop();
               }else if(g=="."){
                   while(st.size() && st.top()!='/'){
                    st.pop();
                }   
                   if(st.size())st.pop();
               }
               if( !st.size()||st.top()!='/')
                 st.push('/'); 
                g.clear();
            }else {
                g.push_back(s[i]);
                st.push(s[i]);
            }
        }
        if(g==".."){
                   
                while(st.size() && st.top()!='/'){
                    st.pop();
                }   
                   if(st.size())st.pop();
                   while(st.size() && st.top()!='/'){
                    st.pop();
                }   
                   if(st.size())st.pop();
               }else if(g=="."){
                   while(st.size() && st.top()!='/'){
                    st.pop();
                }   
                   if(st.size())st.pop();
               }
               if( !st.size()||st.top()!='/')
                 st.push('/'); 
        
               g.clear(); 
        string res;
        while(st.size() && st.top()=='/'){
            st.pop();
        }
        if(st.size()==0)return "/";
        while(st.size()){
            // cout<<st.top()<<" ";
            if(res.size() && res.back()=='/' && st.top()=='/'){
                st.pop();
                continue;
            }
            res.push_back(st.top());
            st.pop();
        }
       
        reverse(res.begin(),res.end());
        return res;
        
    }
};
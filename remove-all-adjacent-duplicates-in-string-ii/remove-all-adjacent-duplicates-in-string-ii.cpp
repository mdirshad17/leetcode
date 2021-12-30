class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
          stack<pair<char,int> > st;
          for(int i=0;i<s.size();i++){
              
             
              if(st.size()){
                  if(s[i]==st.top().first){
                      st.top().second+=1;
                  }else st.push({s[i],1});
              }else st.push({s[i],1});
               while(st.size() && st.top().second==k){
                  st.pop();
              }
          }
        string res;
          while(st.size()){
              int n=st.top().second;
              char c=st.top().first;
              while(n--){
                  res.push_back(c);
              }
              st.pop();
          }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
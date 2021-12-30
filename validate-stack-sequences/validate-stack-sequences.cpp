class Solution {
public:
    bool validateStackSequences(vector<int>& p, vector<int>& po) {
        
        int n=p.size();
        int j=0;
        stack<int> st;
        for(int i=0;i<n;i++){
           if(st.size() && st.top()==po[i]){
               st.pop();
               continue;
           }
            while(j<n){
                st.push(p[j++]);
                if(st.top()==po[i])break;
            }
            
            if(st.top()!=po[i]) return 0;
            else st.pop();
        }
        return 1;
    }
};
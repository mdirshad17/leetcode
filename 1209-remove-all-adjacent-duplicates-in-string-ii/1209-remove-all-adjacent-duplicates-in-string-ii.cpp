class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.size() && st.top().first==s[i]){
                st.top().second++;
            }else {
                st.push({s[i],1});
            }
            while(st.size() && st.top().second==k){
                st.pop();
            }
        }
        string res;
        while(st.size()){
            int n=st.top().second;
            char c=st.top().first;
            for(int i=0;i<n;i++){
                res.push_back(c);
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && t[i]>=t[st.top()]){
                st.pop();
            }
            if(st.size()){
                res[i]=st.top()-i;
            }
            st.push(i);
        }
        return  res;
    }
};
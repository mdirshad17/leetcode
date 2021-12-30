class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) 
    {
       stack<int> st;
        int n=a.size();
        vector<int> res;
       for(int i=0;i<n;i++){
           if(a[i]<0){
               int num=a[i];
               while(num<0 && st.size()){
                   int d=st.top();
                   st.pop();
                   if(abs(num)==d){
                       num=0;
                   }else if(d>abs(num)){
                       num=d;
                   }
               }
               if(num>0) st.push(num);
               else if(num<0) res.push_back(num);
           }else{
               st.push(a[i]);
           }
       }
        vector<int> pos;
        while(st.size()){
            pos.push_back(st.top());
            st.pop();
        }
        reverse(pos.begin(),pos.end());
        for(int i=0;i<pos.size();i++){
            res.push_back(pos[i]);
        }
        return res;
    }
};
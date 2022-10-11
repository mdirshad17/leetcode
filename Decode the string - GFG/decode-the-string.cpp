//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string S){
        stack<char> st;
        int n=S.size();
        for(int i=0;i<n;i++){
             if(S[i]==']'){
                 string H;
                 while(st.size() && st.top()!='['){
                     H.push_back(st.top());
                     st.pop();
                 }
                 reverse(H.begin(),H.end());
                 st.pop();
                 int num=0;
                 int pwr=1;
                 while(st.size() && (st.top()>='0' && st.top()<='9')){
                     num=pwr*(st.top()-'0')+num;
                     pwr=pwr*10;
                     st.pop();
                 }
                 for(int i=0;i<num;i++){
                     for(char c:H){
                         st.push(c);
                     }
                 }
                 
             }else st.push(S[i]);
        }
        string res;
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
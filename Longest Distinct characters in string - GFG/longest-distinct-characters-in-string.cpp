// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int check(int * a){
    for(int i=0;i<26;i++){
        if(a[i]>1) return 0;
    }
    return 1;
}
int good(int m,string & s,int n){
    int a[26]={0};
    for(int i=0;i<m;i++){
        a[s[i]-'a']++;
    }
    if(check(a)) return 1;
    for(int i=m;i<n;i++){
        a[s[i]-'a']++;
        a[s[i-m]-'a']--;
        if(check(a)) return 1;
    } 
   
    return 0;    
}

int longestSubstrDistinctChars (string s)
{
    int n=s.size();
    int ans=0;
     int l=1,r=n;
     while(l<=r){
         int m=(l+r)/2;
         if(good(m,s,n)){
             ans=m;
             l=m+1;
         }else r=m-1;
     }
     return ans;
}
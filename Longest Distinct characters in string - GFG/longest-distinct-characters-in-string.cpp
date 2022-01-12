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



int longestSubstrDistinctChars (string s)
{
    int n=s.size();
    int ans=0;
    int j=0;
    int a[26]={0};
    for(int i=0;i<n;i++){
        a[s[i]-'a']++;
        while(a[s[i]-'a']>1){
            a[s[j]-'a']--;
            j++;
        }
        int len=i-j+1;
        ans=max(ans,len);
    }
    return ans;
}
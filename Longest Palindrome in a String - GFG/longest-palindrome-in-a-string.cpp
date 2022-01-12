// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n=s.size();
        int dp[n+5][n+5];
        memset(dp,0,sizeof(dp));
        int ans=0;
        int si=0;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }else if(g==1){
                    dp[i][j]=(s[i]==s[j]);
                }else{
                    dp[i][j]=((s[i]==s[j]) && dp[i+1][j-1]);
                }
                if(dp[i][j]){
                    int len=j-i+1;
                    if(ans<len){
                        ans=len;
                        si=i;
                    }
                }
            }
        }
        return  s.substr(si,ans);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
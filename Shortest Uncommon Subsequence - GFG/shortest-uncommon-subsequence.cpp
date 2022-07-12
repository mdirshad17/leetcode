// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   int dp[505][505];
    int solve(int s,int n,string & p,int m,string & t,int pr){
        if(pr==INT_MAX)return 0;
        if(s>=n)return 5000;
        if(dp[s][pr+1]!=-1)return dp[s][pr+1];
        int op1=solve(s+1,n,p,m,t,pr);
        int idx=INT_MAX;
        for(int j=pr+1;j<m;j++){
            if(t[j]==p[s]){
                idx=j;
                break;
            }
        }
        int op2=1+solve(s+1,n,p,m,t,idx);
        return dp[s][pr+1]=min(op1,op2);
        
    }
    int shortestUnSub(string S, string T) {
        int n=S.size();
        int m=T.size();
        memset(dp,-1,sizeof(dp));
        int l=solve(0,n,S,m,T,-1);
        if(l>=5000)return -1;
        return l;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends
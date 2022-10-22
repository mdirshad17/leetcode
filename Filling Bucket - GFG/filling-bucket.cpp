//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  #define ll long long
  #define M 100000000
    int fillingBucket(int N) {
       ll ans[N+5];
       memset(ans,0,sizeof(ans));
       ans[0]=0;
       ans[1]=1;
       ans[2]=2;
       for(int i=3;i<=N;i++){
           ans[i]+=ans[i-1];
           ans[i]+=ans[i-2];
           ans[i]=ans[i]%M;
       }
       return ans[N];
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
      int cnt=0;
      while(b){
          b-=(b&(-b));
          cnt++;
      }
      int x=0;
      for(int i=31;cnt && i>=0;i--){
          int num=(1LL<<i);
          if((num&a)==0)continue;
          cnt--;
           x=x|(num);
          
      }
      for(int i=0;cnt && i<=31;i++){
          int num=(1LL<<i);
          if((num&x))continue;
          cnt--;
          x=x|(num);
      }
      return x;
      
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends
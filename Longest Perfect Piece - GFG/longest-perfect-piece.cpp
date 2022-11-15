//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
       multiset<int> mt,mt1;
       int j=0;
       int ans=0;
       for(int i=0;i<N;i++){
           mt.insert(arr[i]);
           mt1.insert(-1*arr[i]);
           while(1){
               int elem1=*mt.begin();
               int elem2=*mt1.begin();
               int diff=abs(elem1+elem2);
               if(diff<=1)break;
               mt.erase(mt.find(arr[j]));
               mt1.erase(mt1.find(-1*arr[j]));
               j++;
           }
           int len=(i-j+1);
           ans=max(ans,len);
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
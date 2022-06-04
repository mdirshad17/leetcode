// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    
    int equilibriumPoint(long long a[], int n) {
    
       int ans=-1;
       long long  tot=0;
       for(int i=0;i<n;i++){
           tot+=a[i];
       }
       long long leftsum=0;
       for(int i=0;i<n;i++){
           leftsum+=a[i];
           long long rightsum=tot-leftsum;
           long long leftsum_wewant=leftsum-a[i];
           if(rightsum==leftsum_wewant){
               return i+1;
           }
           
       }
       return ans;
       
    //   leftsum
    //     tot-leftsum;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
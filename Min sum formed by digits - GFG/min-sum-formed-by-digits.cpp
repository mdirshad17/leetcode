// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    #define ll long long 
    long long int minSum(int arr[], int n)
    {
       sort(arr,arr+n);
       ll ans=0;
       ll sum1=0,sum2=0;
       for(int i=0;i<n;i++){
           if((i&1)==0){
               sum1=sum1*10LL+arr[i]*1LL;
           }else sum2=sum2*10LL+arr[i]*1LL;
       }
       return sum1+sum2;
       
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
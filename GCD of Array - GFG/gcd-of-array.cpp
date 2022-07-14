// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    int gcd(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            // sum=sum+arr[i];
            sum=__gcd(sum,arr[i]);
        }
        return sum;
    }
};


// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}  // } Driver Code Ends
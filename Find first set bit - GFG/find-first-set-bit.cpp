// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    #define ll long long 
    // 10010
    //1100
    unsigned int getFirstSetBit(int n)
    {
       for(int i=0;i<=31;i++){
           int num=(1<<i);
           if((num&n)!=0)return (i+1);
       }
       return 0;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}
  // } Driver Code Ends
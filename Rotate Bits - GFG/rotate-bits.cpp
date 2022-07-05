// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            // 4,3,2,0,1
            // 1,2,3,4,5=>
            // 3,4,5,1,2
            
            // 1,0,4,3,2 
            int num1=0;
            int cnt=16;
             d=d%16;
            int idx=16-d;
            int bitn=0;
            while(bitn<16){
                if((n&(1<<idx))){
                    num1=num1|(1<<bitn);
                }
                idx=(idx+1)%16;
                bitn++;
            }
          
            idx=d;
             int num2=0;
             bitn=0;
            while(bitn<16){
                if((n&(1<<idx))){
                    num2=num2|(1<<bitn);
                }
                idx=(idx+1)%16;
                bitn++;
            }
            return {num1,num2};
        }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
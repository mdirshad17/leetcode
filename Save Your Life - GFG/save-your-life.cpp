//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          map<char,int> mp;
          for(int i=0;i<n;i++){
              mp[x[i]]=b[i];
          }
          int maxsum=INT_MIN;
          int ri=-1;
          int li=-1;
          int minsum=0;
          int ansl=-1,ansr=-1;
          int sum=0;
          n=w.size();
        //   cout<<n<<" ";
          for(int i=0;i<n;i++){
              if(mp.count(w[i])){
                  sum+=mp[w[i]];
              }else sum+=w[i];
              
              int sumh=sum-minsum;
            //   cout<<sum<<" ";
              if(sumh>maxsum){
                  maxsum=sumh;
                  ansl=li;
                  ansr=i;
              }
              if(sum<minsum){
                  minsum=sum;
                  li=i;
              }
          }
        //   cout<<ansl<<" "<<ansr<<endl;
          int len=ansr-ansl;
          return w.substr(ansl+1,len);
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
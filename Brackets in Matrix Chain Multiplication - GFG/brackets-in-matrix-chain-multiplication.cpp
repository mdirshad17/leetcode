// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[30][30];    
    int solve(int l,int r,vector<vector<int> > & v){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=INT_MAX/10;
        for(int i=l;i<r;i++){
            int lp=solve(l,i,v);
            int rp=solve(i+1,r,v);
            int cp=v[l][0]*v[i][1]*v[r][1];
            ans=min(ans,lp+rp+cp);
        }
        return dp[l][r]=ans;
    }string res;
    void getpath(int l,int r,vector<vector<int> > & v){
        
        if(l==r){
            res+=(l+'A');
            return;
        }
        
        int ans=INT_MAX/10;
        int idx=-1;
        for(int i=l;i<r;i++){
            int lp=solve(l,i,v);
            int rp=solve(i+1,r,v);
            int cp=v[l][0]*v[i][1]*v[r][1];
            int tot=lp+rp+cp;
            if(ans>tot){
                ans=tot;
                idx=i;
            }
        }
        res+='(';
        
        getpath(l,idx,v);
        getpath(idx+1,r,v);
        res+=')';
        // return ans;
    }
    string matrixChainOrder(int p[], int n){
      vector<vector<int>>v;
      res.clear();
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<n-1;i++){
          v.push_back({p[i],p[i+1]});
      }
      n=v.size();
      int f=solve(0,n-1,v);
      getpath(0,n-1,v);
      return res;
    //   return "f";
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
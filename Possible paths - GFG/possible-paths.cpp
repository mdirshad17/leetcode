// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  #define M 1000000007
  int dp[55][55][55];
    int solve(int u,int v,vector<vector<int>> & g,int k){
        if(k<0)return 0;
        if(k==0){
            return (u==v);
        }
        if(dp[u][v][k]!=-1)return dp[u][v][k];
        int ans=0;
        for(int i=0;i<g[u].size();i++){
            if(g[u][i]){
                ans+=solve(i,v,g,k-1);
                ans=ans%M;
            }
        }
        return dp[u][v][k]=ans%M;
    } 
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    
	   memset(dp,-1,sizeof(dp)); 
	   return solve(u,v,graph,k);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
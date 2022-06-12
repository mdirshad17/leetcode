// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  #define M 1000000007
  int A[55][55];
  int res[55][55];
int n;
void multiply(int res[][55], int A[][55]) {
	int ans[55][55];
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				ans[i][j] += ((res[i][k]%M)*1LL*(A[k][j]%M))% M;
				ans[i][j] %= M;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// cout << ans[i][j] << " ";
			res[i][j] = (ans[i][j] % M);
		}
	}
}
int  POW_X(int k) {
    
	
	memset(res, 0, sizeof(res));
	for (int i = 0; i < 55; i++) {
		res[i][i] = 1;
	}

	while (k) {
		if (k & 1) {
			multiply(res, A);
		}
		k = k / 2;
		multiply(A, A);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		    
// 			(ans += res[i][j]) %= M;
// 			ans = ans % M;
		}
		}
	return ans;
}
//   int dp[55][55];
//     int solve(int u,int v,vector<vector<int>> & g,int k){
//         if(k<0)return 0;
//         if(k==0){
//             return (u==v);
//         }
//         if(dp[u][k]!=-1)return dp[u][k];
//         int ans=0;
//         for(int i=0;i<g[u].size();i++){
//             if(g[u][i]){
//                 ans+=solve(i,v,g,k-1);
//                 ans=ans%M;
//             }
//         }
//         return dp[u][k]=ans%M;
//     } 
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    memset(A,0,sizeof(A));
	    n=graph.size();
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=n;j++){
	            A[i][j]=graph[i-1][j-1];
	        }
	    }
	    POW_X(k);
	    return (res[u+1][v+1]%M);
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
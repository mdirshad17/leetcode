//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    #define pii pair<int,int>
map<pii, pii> parent;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
pii getp(pii u) { return (u == parent[u] ? u : (parent[u] = getp(parent[u])));}
int connect(pii u, pii v) {
	u = getp(u), v = getp(v);
	if (u == v) return 1;
	parent[v] = u;
	return 0;
}
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &O) {
     int R[n][m];    
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             parent[{i,j}]={i,j};
             R[i][j]=0;
          }
      }
      vector<int> ans;
      int cnt=0;
      for(int i=0;i<O.size();i++){
          int x=O[i][0];
          int y=O[i][1];
          set<pii> st;
          if(R[x][y]){
              ans.push_back(cnt);
              continue;
          }
          for(int j=0;j<4;j++){
              int X=x+dx[j];
              int Y=y+dy[j];
              if(X>=0 &&  X<n && Y>=0 && Y<m && R[X][Y]){
                  pii P=getp({X,Y});
                  st.insert(P);
              }
          }
          R[x][y]=1;
          if((st.size())==0){
                  cnt++;
              }else{
                  for(auto z:st){
                      connect(z,{x,y});
                      
                  }
                  cnt-=(st.size()-1);
              }
              
              ans.push_back(cnt);
      }
      
      return ans;
      
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
vector<int> v;
vector<vector<int>> res;
int ns,ms;
    void solve(int r,int c,vector<vector<int> > & grid){
        if(r>=ns||c>=ms)return;
        v.push_back(grid[r][c]);
        if(r==ns-1 && c==ms-1){
            res.push_back(v);
            v.pop_back();
            return;
        }
        solve(r+1,c,grid);
        solve(r,c+1,grid);
        v.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {    ns=n;
         ms=m;
        res.clear();
         v.clear();
         solve(0,0,grid);
         return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends
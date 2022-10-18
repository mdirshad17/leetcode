//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
	    vector<int> v[2*N];
	    int num=1;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            v[i+j].push_back(A[i][j]);
	        }
	    }
	    vector<int> ans;
	    for(int i=0;i<2*N;i++){
	        for(int x:v[i]){
	            ans.push_back(x);
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
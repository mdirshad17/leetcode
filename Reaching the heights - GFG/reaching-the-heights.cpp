// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    vector<int> res;
    sort(a,a+n);
    int l=0,r=n-1;
    for(int i=0;i<n;i++){
        if((i&1)){
            res.push_back(a[l++]);
        }else res.push_back(a[r--]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(i&1){
            sum-=res[i];
        }else sum+=res[i];
        // cout<<sum<<" ";
        if(sum==0)return {-1};
    }
    return res;
}

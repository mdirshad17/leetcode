// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    bool brainGame(vector<int>nums) {
        // Code here.
        int arr[1005];
        memset(arr,0,sizeof(arr));
      
        // calculating maximum number of operation that can be performed
        // on a number
        for(int i=2;i<=1000;i++){
            for(int j=2*i;j<=1000;j+=i){
                arr[j]=max(arr[j],1+arr[i]);
            }
        }
        int xorsum=0;
        for(int i=0;i<nums.size();i++){
            xorsum=xorsum^arr[nums[i]];
        }
        return (xorsum!=0);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends
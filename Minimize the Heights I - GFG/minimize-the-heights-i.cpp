// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
#define pii pair<int,int>
    int getMinDiff(int arr[], int n, int k) {
         vector<pii> v;
         for(int i=0;i<n;i++){
             v.push_back({arr[i]-k,i});
             v.push_back({arr[i]+k,i});
         }
         sort(v.begin(),v.end());
         unordered_map<int,int> mp;
         int ans=INT_MAX;
         int j=0;
         for(int i=0;i<v.size();i++){
             mp[v[i].second]++;
             while(mp.size()>=n){
                 int diff=v[i].first-v[j].first;
                 ans=min(ans,diff);
                 mp[v[j].second]--;
                 if(mp[v[j].second]==0){
                     mp.erase(v[j].second);
                 }
                 j++;
             }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
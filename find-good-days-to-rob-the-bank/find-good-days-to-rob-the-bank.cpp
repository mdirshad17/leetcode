class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int time) {
        int n=arr.size();
        vector<int> a(n,0),b(n,0);
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1])a[i]=1+a[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1])b[i]=1+b[i+1];
        }
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(a[i]>=time && b[i]>=time){
                res.push_back(i);
            }
        }
        return res;
        
    }
};
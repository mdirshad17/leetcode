class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int arr[n+5];
        memset(arr,0,sizeof(arr));
        for(auto x:queries){
            int u=x[0];
            int v=x[1];
            arr[u]+=1;
            arr[v+1]-=1;
        }
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0;i<n;i++){
            if(arr[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};
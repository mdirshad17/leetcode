class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int pre[n];
        memset(pre,0,sizeof(pre));
        int l=*max_element(arr.begin(),arr.end());
        if(l<=0)return l;
        pre[0]=max(pre[0],arr[0]);
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i],arr[i]+pre[i-1]);
        }
        int suff[n];
        memset(suff,0,sizeof(suff));
        suff[n-1]=max(suff[n-1],arr[n-1]);
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i],suff[i+1]+arr[i]);
        }
        int ans=max(pre[n-1],suff[0]);
        for(int i=0;i<n;i++){
            int left=((i-1>=0)?pre[i-1]:0);
            int right=((i+1<n)?suff[i+1]:0);
            // cout<<left<<" "<<right<<endl;
            ans=max(ans,left+right);
        }
        return ans;
        
    }
};
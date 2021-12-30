class Solution {
public:
    vector<int> left_g(vector<int> & arr){
        int n=arr.size();
        vector<int> left(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.size()) left[i]=st.top();
            st.push(i);
        }
        return left;
    }
    vector<int> right_g(vector<int> & arr){
        int n=arr.size();
        vector<int> right(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.size()) right[i]=st.top();
            st.push(i);
        }
        return right;
    }
    #define ll long long 
    #define M 1000000007
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> left=left_g(arr);
        vector<int> right=right_g(arr);
        ll ans=0;
        for(int i=0;i<n;i++){
           // cout<<left[i]<<" "<<right[i]<<" \n";
            ll w=(i-left[i])*1LL*(right[i]-i)*1LL;
            // cout<<w<<" ";
            ans=ans+(w*arr[i]*1LL)%M;
            ans=ans%M;
        }
        return ans;
        
    }
};
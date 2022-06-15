class Solution {
public:
    int subarraysum(vector<int> & v,int k){
        int ans=INT_MIN;
        set<int> st;
        st.insert(0);
        st.insert(INT_MAX/10);
        int sum=0;
        for(int x:v){
            sum+=x;
            auto it=st.lower_bound(sum-k);
            int val=(*it);
            int sumh=sum-val;
            ans=max(ans,sumh);
            st.insert(sum);
        }
        return ans;
        
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> b(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    b[k]+=matrix[j][k];
                }
                int cnt=subarraysum(b,K);
                ans=max(cnt,ans);
            }
        }
        return ans;
    }
};
class Solution
{
    public:
        int process(vector<int> & b,int k){
            int n=b.size();
            int ans=INT_MIN;
            set<int> st;
            st.insert(INT_MAX/10);
            st.insert(0);
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=b[i];
                int sv=(sum-k);
                auto it=st.lower_bound(sv);
                int sumh=sum-(*it);
                ans=max(ans,sumh);
                st.insert(sum);
            }
            return ans;
        }
        int maxSumSubmatrix(vector<vector < int>> &matrix, int k)
        {

            int n = matrix.size();
            int m = matrix[0].size();
            int ans = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                vector<int> b(m, 0);
                for (int j = i; j < n; j++)
                {
                    for (int k = 0; k < m; k++)
                    {
                        b[k] += matrix[j][k];
                    }
                    int l = process(b, k);
                    if(l==k)return l;
                    ans = max(ans, l);
                }
            }
            return ans;
        }
};
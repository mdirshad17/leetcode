class Solution {
public:
    int solve(vector<int> & v,int k){
        int n=v.size();
        set<int> st;
        int diff=INT_MAX;
        st.insert(0);
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=v[i];
            int sy=sum-k;
            auto it=st.lower_bound(sy);
            if(it!=st.end()){
              
                int val=(*it);
                sy=sum-val;
                int diffx=abs(k-sy);
                if(diffx<diff){
                    diff=diffx;
                    ans=sy;
                }
                
               
            }
            st.insert(sum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int mk) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        int diff=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int>v(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    v[k]+=matrix[j][k];
                }
                int p=solve(v,mk);
            if(p!=INT_MAX){
                 int diffx=abs(mk-p);
                if(diffx<diff){
                    diff=diffx;
                    ans=p;
                }
            }
            } 
           
            
        }
        return ans;
    }
};
class Solution {
public:
    const static int N=1e5+1;
    int l[N];
    int r[N];
    int good(int m,vector<int> & a){
        int n=a.size();
        // cout<<m<<endl;
        for(int i=0;i+m<=n;i++){
           int lidx=i-1;
           int ridx=i+m; 
           int li=(i>0?l[i-1]:0);
           int ri=r[i+m];
            // cout<<li<<" "<<ri<<" \n";
           int lel=(i>0?a[i-1]:0);
           int rel=i+m<n?a[i+m]:INT_MAX;
           if(lel<=rel && li+ri+m==n)return 1; 
        }
        return 0;
        
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
       int n=arr.size();
    
        l[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) l[i]=1+l[i-1];
            else l[i]=1;
        }
        r[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1])r[i]=1+r[i+1];
            else r[i]=1;
        }
        int sum=l[n-1];
        if(sum==n) return 0;
        int l=1,r=n-1;
        int ans=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(good(m,arr)){
                 ans=m;
                r=m-1;
            }else l=m+1;
        }
        return ans;
        
        
        
        
    }
};
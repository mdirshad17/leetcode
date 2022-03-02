class Solution {
public:
    int bs(vector<vector<int> > &v,int val){
        int n=v.size();
        int l=0,r=n-1;
        int ans=n+1;
        while(l<=r){
            int m=(l+r)/2;
            if(v[m][0]>=val){
                ans=m;
                r=m-1;
            }else l=m+1;
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end(),[](vector<int> & a,vector<int> & b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        });
        int n=events.size();
        int max_v[n];
        memset(max_v,0,sizeof(max_v));
        max_v[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            max_v[i]=max(max_v[i+1],events[i][2]);
        }
        // for(int i=0;i<n;i++)cout<<max_v[i]<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            int geti=bs(events,events[i][1]+1);
            int sum=events[i][2];
            if(geti<n){
                sum+=max_v[geti];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
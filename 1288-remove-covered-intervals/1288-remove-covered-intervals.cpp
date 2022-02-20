class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        
        int n=v.size();
        sort(v.begin(),v.end(),[](vector<int> & a,vector<int> & b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        // for(int i=0;i<n;i++){
        //     cout<<v[i][0]<<" "<<v[i][1]<<endl;
        // }
        int si=-1,ei=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(ei>=v[i][1]){
                ans++;
            }else{
                ei=v[i][1];
                si=v[i][0];
            }
        }
        return n-ans;
        
    }
};
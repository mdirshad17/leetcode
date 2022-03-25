class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(),costs.end(),[](vector<int>& a,vector<int> & b){
             return (a[0]+b[1])<(a[1]+b[0]); 
        });
        int ans=0;
        int n=costs.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                ans+=costs[i][0];
            }else{
            ans+=costs[i][1];}
        }
        cout<<ans<<endl;
        return ans;
    }
};
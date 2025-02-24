class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        
        long long ans=0;
        int n=grid.size();
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end());
            if(limits[i]!=0){
                // cout<<grid[i].back()<<" \n";
              pq.push({grid[i].back(),i});
              }
        }
        while(k && pq.size()){
            pair<int,int> tp=pq.top();
            pq.pop();
            ans+=(1LL*tp.first);
            int idx=tp.second;
            grid[idx].pop_back();
            limits[idx]--;
            if(limits[idx]!=0){
                pq.push({grid[idx].back(),idx});
            }
            k--;
        }
        return ans;
    }
};